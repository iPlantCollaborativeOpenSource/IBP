(function($) {
	$(document).ready(function() {
		$('.messages.warning, .messages.status').attr('title', 'Click to dismiss').click(function() {
			$(this).animate({'opacity':'hide','height':'hide'}, function() {$(this).remove()});
		});
	});
})(jQuery);