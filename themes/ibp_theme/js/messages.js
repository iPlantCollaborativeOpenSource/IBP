(function($) {
	function dismiss(message) {
		$(message).animate({'opacity':'hide','height':'hide'}, function() {$(this).remove()});
	}
	$(document).ready(function() {
		setTimeout(
			function() {
				$('.messages.status').each(function() {
					dismiss(this);
				});
			}, 5000);
		
		$('.messages.warning, .messages.status').attr('title', 'Click to dismiss').click(function() {
			dismiss(this);
		});
	});
})(jQuery);