(function($) {
	$(document).ready(function() {
		$('.messages.warning, .messages.status, .messages.success').attr('title', 'Click to dismiss').click(function() {
			$(this).animate({'opacity':'hide','height':'hide'}, function() {$(this).remove()});
		});
		
		$('#edit-search-theme-form-1').bind('focus', function() {
			var $this = $(this),
					val = $this.val();
			if (val == 'Search IBP') {
				$this.val('').removeClass('default');
			}
		}).bind('blur', function() {
			var $this = $(this),
					val = $this.val();
			if (val == '') {
				$this.val('Search IBP').addClass('default');
			}
		}).trigger('blur');
	});
})(jQuery);