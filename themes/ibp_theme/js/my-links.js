(function($) {
	$(document).ready(
		function() {
			var mylinks_trg = $('#my-links');
			function show_my_links() {
				$('#my-links ul').slideDown('fast');
				mylinks_trg.addClass('my-links-visible');
			}
			function hide_my_links() {
				$('#my-links ul').hide('fast');
				mylinks_trg.removeClass('my-links-visible');
			}
			
			mylinks_trg.bind('mouseenter', function() {
				clearTimeout(mylinks_trg._t);
				mylinks_trg._t = setTimeout(show_my_links, 250);
			});
			
			mylinks_trg.bind('mouseleave', function() {
				clearTimeout(mylinks_trg._t);
				mylinks_trg._t = setTimeout(hide_my_links, 500);
			});
		}
	);
})(jQuery);