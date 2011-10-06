Drupal.behaviors.ibp_menu_blocks = function(context) {
	$('.menu_block_wrapper').each(function() {
		var menu = $(this);
		menu.find('li:not(.active-trail).expanded').removeClass('expanded');
		menu.find('li:not(.active-trail) ul').hide();
		menu.find('a').bind('click', function() {
			var $this = $(this);
			var li = $this.parent();
			if (li.find('ul').length > 0) {
				if (li.hasClass('expanded')) {
					li.find('ul').slideUp(function() {li.removeClass('expanded');});
				} else {
					li.find('ul').slideDown();
					li.addClass('expanded')
				}
				return false;
			}
		});
	});
}