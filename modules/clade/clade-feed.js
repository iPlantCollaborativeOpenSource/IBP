Drupal.clade.initFeed = function(clade_id) {
	$('form.feed-options').submit(
			function() {
				var that = $(this);
				var bubble = that.find('input[name=filter]').is(':checked') ? 1 : 0;
				$.ajax({
					'url': Drupal.settings.basePath + 'clade/feed/' + clade_id + '/' + bubble,
					'dataType' : 'json',
					'beforeSend': function() {
						$('.throbber').addClass('active');
					},
					'success': function(resp) {
						$('.clade-feed').fadeOut('fast',
							function() {
								$(this).html(resp.body).fadeIn('fast');
								Drupal.attachBehaviors($(this));
							}
						);
					},
					'complete': function() {
						$('.throbber').removeClass('active');
						$('.mp-advanced-feed-more').removeClass('no-more');
					}
				});
				return false;
			}
		);
	$('form.feed-options :checkbox').change(
			function() {
				$(this).parents('form:first').submit();
				return false;
			}
		);
	$('.mp-advanced-feed-more').click(
			function() {
				var bubble = $('form.feed-options').find('input[name=filter]').is(':checked') ? 1 : 0;
				var offset = $('.clade-feed').children().length;
				$.ajax({
					'url': Drupal.settings.basePath + 'clade/feed/' + clade_id + '/' + bubble + '/' + offset,
					'dataType': 'json',
					'beforeSend': function() {
						$('.mp-advanced-feed-more').addClass('throbber active');
					},
					'success': function(resp) {
							if (resp.body && resp.body.length > 0) {
								$('.clade-feed').append(resp.body);
								Drupal.attachBehaviors($('.clade-feed'));
							} else {
								$('.mp-advanced-feed-more').addClass('no-more');
							}
					},
					'complete': function() {
						$('.mp-advanced-feed-more').removeClass('throbber active');
					}
				});
			}
		);
};