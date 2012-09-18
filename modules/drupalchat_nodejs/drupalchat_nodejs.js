(function($) {
  Drupal.drupalchat = Drupal.drupalchat || {};
  
  Drupal.drupalchat.removeDuplicates = function() {
    var liText = '',
      liList = $('#chatpanel .subpanel ul li'),
      listForRemove = [];
    $(liList).each(function() {
      var text = $(this).text();
      if (liText.indexOf('|' + text + '|') == -1) liText += '|' + text + '|';
      else listForRemove.push($(this));
    });
    $(listForRemove).each(function() {
      $(this).remove();
      //drupalchat.online_users = drupalchat.online_users - 1;
      $('#chatpanel .online-count').html($('#chatpanel .subpanel ul > li').size());
    });
  };
  
  Drupal.drupalchat.processChatDataNodejs = function(data) {
    if (data) {
      // Play new message sound effect
      var obj = swfobject.getObjectById("drupalchatbeep");
      if (obj) {
        obj.drupalchatbeep(); // e.g. an external interface call
      }
    }
    //Add div if required.
    chatboxtitle = data.uid1;
    if ($("#chatbox_" + chatboxtitle).length <= 0) {
      createChatBox(chatboxtitle, data.name, 1);
    } else if ($("#chatbox_" + chatboxtitle + " .subpanel").is(':hidden')) {
      if ($("#chatbox_" + chatboxtitle).css('display') == 'none') {
        $("#chatbox_" + chatboxtitle).css('display', 'block');
      }
      $("#chatbox_" + chatboxtitle + " a:first").click(); //Toggle the subpanel to make active
      $("#chatbox_" + chatboxtitle + " .chatboxtextarea").focus();
    }
    data.message = data.message.replace(/{{drupalchat_newline}}/g, "<br />");
    data.message = emotify(data.message);
    if ($("#chatbox_" + chatboxtitle + " .chatboxcontent .chatboxusername a:last").html() == data.name) {
      $("#chatbox_" + chatboxtitle + " .chatboxcontent").append('<p>' + data.message + '</p>');
    } else {
      var currentTime = new Date();
      var hours = currentTime.getHours();
      var minutes = currentTime.getMinutes();
      if (hours < 10) {
        hours = "0" + hours;
      }
      if (minutes < 10) {
        minutes = "0" + minutes;
      }
      $("#chatbox_" + chatboxtitle + " .chatboxcontent").append('<div class="chatboxusername"><span class="chatboxtime">' + hours + ':' + minutes + '</span><a href="' + Drupal.settings.basePath + 'user/' + chatboxtitle + '">' + data.name + '</a></div><p>' + data.message + '</p>');
    }
    $("#chatbox_" + chatboxtitle + " .chatboxcontent").scrollTop($("#chatbox_" + chatboxtitle + " .chatboxcontent")[0].scrollHeight);
    $.titleAlert(Drupal.settings.drupalchat.newMessage, {
      requireBlur: true,
      stopOnFocus: true,
      interval: 800
    });
  };
  
  Drupal.drupalchat.processUserOnline = function(data) {
    if (data.uid != Drupal.settings.drupalchat.uid) {
      $('.no-users', '#chatpanel').parent().remove();
      if ($("a #drupalchat_user_" + data.uid).length <= 0) {
        $('#chatpanel .subpanel ul > li.link').remove();
        $('#chatpanel .subpanel ul').append('<li class="status-' + '1' + '"><a class="' + data.uid + '" href="#" id="drupalchat_user_' + data.uid + '">' + data.name + '</a></li>');
        $('#chatpanel .online-count').html($('#chatpanel .subpanel ul > li').size());
      }
      
      Drupal.drupalchat.changeStatus('chatbox_'+data.uid, data.status);
    }
    Drupal.drupalchat.removeDuplicates();
  };
  
  Drupal.drupalchat.processUserOffline = function(data) {
    if (data.uid != Drupal.settings.drupalchat.uid) {
      var buddyItem = $('#drupalchat_user_' + data.uid),
          chatbox = $('#chatbox_' + data.uid);
      if (buddyItem.length > 0) {
        buddyItem.parent().remove();
        var count = $('#chatpanel .subpanel ul > li').size();
        $('#chatpanel .online-count').html(count);
        if (count == 0) {
          $('#chatpanel .subpanel ul').append(Drupal.settings.drupalchat.noUsers);
        }
      }
      
      Drupal.drupalchat.changeStatus('chatbox_'+data.uid, data.status);
    }
    Drupal.drupalchat.removeDuplicates();
  };
  
  Drupal.Nodejs.callbacks.drupalchatNodejsMessageHandler = {
    callback: function(message) {
      switch (message.type) {
      case 'newMessage':
        Drupal.drupalchat.processChatDataNodejs($.parseJSON(message.data));
        break;
      case 'userOnline':
        Drupal.drupalchat.processUserOnline(message.data);
        break;
      case 'userOffline':
        Drupal.drupalchat.processUserOffline(message.data);
        break;
      case 'createChannel':
        $.post(Drupal.settings.drupalchat.addUrl);
        break;
      }
    }
  };

})(jQuery);
