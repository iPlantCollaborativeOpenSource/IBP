Drupal.clade_files = {
  init: function (context) {
    Drupal.clade_files.wireUpMenus(context);
    $('a.dirlink', context).unbind('click').bind('click',
        function () {
        	var dir;
        	if (this.tagName.toLowerCase() == 'a') {
        		dir = $(this).parent();
        	} else {
        		dir = $(this);
        	}
          if (dir.hasClass('opendir')) {
            Drupal.clade_files.closeDirectory(dir);
          } else {
            Drupal.clade_files.openDirectory(dir);
          }
          return false;
        }
      );
    Drupal.clade_files.stripeFileBrowser();
  },
  wireUpMenus: function(context) {
    $('.directory', context)
    	.unbind('mouseenter mouseleave') // prevent multiple events firing
			.hoverIntent({
        over: function (e) {
          $(this).children('ul').animate({'opacity':'show'}, 'fast');
        },
        timeout: 5,
        out: function (e) {
          $(this).children('ul').animate({'opacity':'hide'}, 'fast');
        }
      });
    $('.clade-fs-new-subfolder', context).unbind('click').bind('click',
        function() {
        	var formUrl = $(this).attr('href');
        	var directory = $(this).parents('.directory');
        	$.ajax({
        		url: formUrl + '/ajax',
        		dataType: 'json',
        		success: function(resp) {
        				var form = $(resp.form);
        				form.appendTo('body').dialog({
        						title: 'Create new folder',
        						modal: true,
        						width: 'auto',
        						height: 'auto',
        						close: function(event, ui) {
        							form.remove();
        						}
        					});
        				form.bind('submit', function() {
        					$.ajax({
        						type: 'post',
        						url: form.attr('action') + "/submit",
        						data: form.serialize(),
        						dataType: 'json',
        						success: function(resp) {
        							if (resp.valid) {
        								form.dialog('close');
        								Drupal.clade_files.closeDirectory(directory);
        								directory.parent().next('.item-level').remove();
        								Drupal.clade_files.openDirectory(directory);
        							} else {
        								$('#subdirname_wrapper').replaceWith(resp.form);
        								$('#subdirname_wrapper').prepend(resp.messages);
        							}
										},
        						error: function() {
										}
									});
        					return false;
									});
							}
        		});
//           var id = $(this).attr("id").split("_")[4];
//           $.ajax({
//             url: "files/" + id + "/new-subdir",
//             dataType: "json",
//             success: function(resp) {
//               $("body").append(resp.form);
//               eval(resp.script);
//             },
//           });
					return false;
        }
      );
  },
  openDirectory: function(directory) {
    var item = directory.parent();
    if (item.next('.item-level').length == 0) {
      var dirurl = directory.find('a').attr('href');
      $.ajax({
          url: dirurl + "?ajax=true",
          dataType: 'json',
          success: function(resp) {
            item.after(resp.contents);
            Drupal.attachBehaviors(item.next());
            directory.find('a.dirlink').trigger('click');
          }
        });
    } else {
      var callback = function() {
        Drupal.clade_files.stripeFileBrowser();
        directory.removeClass('closeddir').addClass('opendir');
      }
      item.next('.item-level').slideDown('fast', callback);
    }
  },
  closeDirectory: function(directory) {
    var callback = function() {    
      Drupal.clade_files.stripeFileBrowser();
      directory.removeClass('opendir').addClass('closeddir');
    }
    directory.parent().next('.item-level').slideUp('fast', callback);
  },
  stripeFileBrowser: function() {
    $('#clade-files-view-fs .item:visible:even').addClass('even').removeClass('odd');
    $('#clade-files-view-fs .item:visible:odd').addClass('odd').removeClass('even');
  },
//   showMask: function() {
//   	var form = $(".mask-content")
//   	var h = ($(window).height() - form.height()) / 3;
// 		var w = ($(window).width() - form.width()) / 2;
// 		form.css({"left":w + "px", "top":h + "px"});
//     $(".mask").fadeIn('fast');
//     form.fadeIn('fast');
//   },
//   removeMask: function() {
//     $(".mask-content").fadeOut('fast', function() { $(".mask-content").remove(); });
//     $(".mask").fadeOut('fast', function() { $(".mask").remove(); });
//   },
};

Drupal.behaviors.clade_files = function(context) {
	Drupal.clade_files.init(context);
	if (context.nodeName == "#document") {
		$('.directory.closeddir:first a.dirlink', context).trigger('click');
	}
}