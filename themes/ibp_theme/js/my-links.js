(function($) {
	$(document).ready(
		function() {
			var mylinks = $('#block-menu-menu-my-links ul ul'),
			    mylinks_trg = mylinks.parent();
			
			mylinks_trg.addClass('my-links');
			
			function show_my_links() {
				mylinks.slideDown('fast');
				mylinks_trg.addClass('my-links-visible');
			}
			function hide_my_links() {
				mylinks.slideUp('fast', function(){mylinks_trg.removeClass('my-links-visible');});
			}
			
			mylinks_trg.bind('mouseenter', function() {
				clearTimeout(mylinks_trg._t);
				mylinks_trg._t = setTimeout(show_my_links, 250);
			});
			
			mylinks_trg.bind('mouseleave', function() {
				clearTimeout(mylinks_trg._t);
				mylinks_trg._t = setTimeout(hide_my_links, 500);
			});
			
			mylinks_trg.children('a').attr('href', '#').bind('click', function() {
				return false;
			});
		}
	);
})(jQuery);