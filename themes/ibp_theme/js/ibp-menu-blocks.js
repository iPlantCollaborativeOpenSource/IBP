Drupal.behaviors.ibp_menu_blocks = function(context) {
	$('.menu_block_wrapper').each(function() {
		var menu = $(this);
		menu.find('li:not(.active-trail).expanded').removeClass('expanded');
		menu.find('li:not(.active-trail) ul').hide();
		menu.find('li.active-trail').filter(':last').addClass('active').children('a').addClass('active');
		$('a', menu).each(function(i,o) {
			var a = $(o);
			var exp = $('<a class="menu-expander">').attr('href', a.attr('href'));
			a.append(exp);
		});
		menu.find('a.menu-expander').bind('click', function(e) {
			e.stopPropagation();
			var $this = $(this);
			var li = $this.parent().parent(),
					ul = li.find('ul:first');
			if (ul.length > 0) {
				if (li.hasClass('expanded')) {
					ul.slideUp(function() {li.removeClass('expanded');});
				} else {
					ul.slideDown();
					li.addClass('expanded')
				}
				return false;
			}
		});
	});
}