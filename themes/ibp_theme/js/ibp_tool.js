(function($) {
	$.extend({
		delay: function(fun, millis) {
			clearTimeout(this._t);
			this._t = setTimeout(fun, millis);
		}
	});
	$(document).ready(
		function() {
			$('.screenshots a, .rollovers a').fancybox({"titlePosition":"inside"});
			$('.rollover').hide().eq(0).show();
			$('.screenshots a').bind('mouseenter', function() {
				clearTimeout(this._t);
				var $this = $(this);
				$.delay(function() {
					if (! $this.hasClass('active')) {
						$('.screenshots a').removeClass('active');
						$this.addClass('active');
						$('.rollover').fadeOut();
						var i = $('.screenshots a').index($this);
						$('.rollover-'+i).fadeIn();
					}
				}, 200);
			}).eq(0).addClass('active');
		}
	);
})(jQuery);