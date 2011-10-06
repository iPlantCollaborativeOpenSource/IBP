Drupal.behaviors.ibptools_nav_menu = function(context) {
	var menu = $('ul.ibtools_nav_menu');
	
	menu.find('ul.ibtools_nav_submenu').hide();
	menu.find('li.ibtools_nav_menu_item a.active').parent().addClass('expanded');
	menu.find('li.ibtools_nav_submenu_item a.active')
		.parents('li.ibtools_nav_menu_item').addClass('expanded');
	menu.find('li.ibtools_nav_menu_item.expanded')
			.find('ul.ibtools_nav_submenu').show();
	
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
}