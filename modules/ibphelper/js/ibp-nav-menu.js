Drupal.behaviors.ibptools_nav_menu = function(context) {
	var menu = $('ul.ibtools_nav_menu');
	
	menu.find('ul.ibtools_nav_submenu').hide();
	menu.find('li.ibtools_nav_menu_item a.active').parent().addClass('expanded');
	menu.find('li.ibtools_nav_submenu_item a.active')
		.parents('li.ibtools_nav_menu_item').addClass('expanded');
	menu.find('li.ibtools_nav_menu_item.expanded')
			.find('ul.ibtools_nav_submenu').show();
	
	menu.find('li').bind('click', function() {
		var $this = $(this);
		if ($this.find('ul').length > 0) {
			if (! $this.hasClass('expanded')) {
				$this.find('ul').slideDown();
				$this.addClass('expanded')
				return false;
			}
		}
	});
}