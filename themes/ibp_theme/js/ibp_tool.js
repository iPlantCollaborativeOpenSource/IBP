(function($) {
	$.extend({
		delay: function(fun, millis) {
			clearTimeout(this._t);
			this._t = setTimeout(fun, millis);
		}
	});
	$.fn.rollovers = function() {
		return this.each(function() {
			var ctx = this;
			
			$('.screenshots a, .rollovers a', ctx).fancybox({"titlePosition":"over","padding":1,"overlayColor":"#000","overlayOpacity":0.5});
			$('.rollover', ctx).hide().eq(0).show();
			$('.screenshots a', ctx).bind('mouseenter', function() {
				clearTimeout(this._t);
				var $this = $(this);
				$.delay(function() {
					if (! $this.hasClass('active')) {
						$('.screenshots a', ctx).removeClass('active');
						$this.addClass('active');
						$('.rollover', ctx).fadeOut();
						var i = $('.screenshots a', ctx).index($this);
						$('.rollover-'+i, ctx).fadeIn();
					}
				}, 200);
			}).eq(0).addClass('active');
		});
	}
	$(document).ready(
		function() {
			$('.tool-screenshots').rollovers();
		}
	);
})(jQuery);