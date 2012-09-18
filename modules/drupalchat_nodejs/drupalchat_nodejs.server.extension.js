/**
 * DrupalChat server extension for nodejs
 *
 * Add this extension name to the "extensions" in node.config.js
 */

var publishMessageToClient;
var drupalchat_users = {};
var drupalchat_names = {};

exports.setup = function (config) {
  publishMessageToClient = config.publishMessageToClient;

  process.on('client-authenticated', function (sessionId, authData) {
    if (config.settings.debug) {
      console.log('Authenticated/connected - ' + authData.uid);
    }
    
    //get others info
    if(authData.uid != 0) {
      for (var user in drupalchat_users) {
        if(authData.uid != drupalchat_users[user] && drupalchat_names[user]) {
          if (config.settings.debug) {
            console.log('Getting - ' + user + ' with name - ' + drupalchat_names[user] + ', for ' + authData.uid);
          }
          publishMessageToClient(sessionId, {type: 'userOnline', data: {uid: user, name: drupalchat_names[user]}, callback: 'drupalchatNodejsMessageHandler'});
        }
      }
      
      //create own channel
      publishMessageToClient(sessionId, {type: 'createChannel', data: 'create', callback: 'drupalchatNodejsMessageHandler'});
      
      //add me
      if (config.settings.debug) {
        console.log('Added - ' + authData.uid);
      }
      drupalchat_users[authData.uid] = sessionId;
    }
  })
  
  .on('message-published', function (message, i) {
    if (config.settings.debug) {
      console.log('Msg - ' + message.type);
    }
    if (message.type == 'sendName') {
      var data = JSON.parse(message.data);
      
      // update name
      if (config.settings.debug) {
        console.log('Name ' + data.name);
      }
      drupalchat_names[data.uid] = data.name;
      
      //send to others
      for (var user in drupalchat_users) {
        if (user != data.uid) {
          if (config.settings.debug) {
            console.log('Sending - ' + data.uid + ' to ' + user);
          }
          publishMessageToClient(drupalchat_users[user], {type: 'userOnline', data: {uid: data.uid, name: data.name, status: data.status}, callback: 'drupalchatNodejsMessageHandler'});
        }
      }
    } else if (message.type == 'sendStatus') {
      var data = JSON.parse(message.data);
      
      // update name
      if (config.settings.debug) {
        console.log('Name ' + data.name);
        console.log('Status ' + data.status);
      }
      
      if (data.status == 1) {
        drupalchat_names[data.uid] = data.name;
        var type = 'userOnline';
      } else {
        delete drupalchat_names[data.uid];
        delete drupalchat_users[data.uid];
        var type = 'userOffline';
      }
      
      //send to others
      for (var user in drupalchat_users) {
        if (user != data.uid) {
          if (config.settings.debug) {
            console.log('Sending - ' + data.uid + ' to ' + user);
          }
          publishMessageToClient(drupalchat_users[user], {type: type, data: {uid: data.uid, name: data.name, status: data.status}, callback: 'drupalchatNodejsMessageHandler'});
        }
      }
    }
  })
  
  .on('client-disconnect', function (sessionId) {
    var u = 0;
    for (var user in drupalchat_users) {
        if(drupalchat_users[user] == sessionId) {
          u = user;
          break;
        }
    }
    if (config.settings.debug) {
      console.log('Disconnected - ' + u);
    }
    data = {
      uid: u,
      name: drupalchat_names[u]
    };
    delete drupalchat_names[u];
    delete drupalchat_users[u];
    if (u != 0) {
      for (var user in drupalchat_users) {
        if (drupalchat_users[user] != sessionId) {
          publishMessageToClient(drupalchat_users[user], {type: 'userOffline', data: data, callback: 'drupalchatNodejsMessageHandler'});
        }
      }
    }
  });
};

