Drupal.behaviors.teaser_comments = function(context) {
		function bindTeaserReply(elems) {
			$.each(elems, function() {
				var tc = $(this);
				var tcrf = tc.find('.teaser-comment-reply-form');
				tc.find('a.teaser-comment-reply').bind('click',
						function() {
							tc.addClass('replying');
							tcrf.slideDown('fast').find('textarea').focus();
							return false;
						}
					);
				tcrf.find('form').submit(
						function() {
							var form = $(this);
							$('.error', form).removeClass('error').find('.error-message').remove();
							$.ajax({
								url: form.attr('action'),
								type: 'post',
								data: form.serialize(),
								dataType: 'json',
								success: function(data, status, xmlReq){
										if (data.success) {
											var reply = $(data.body);
											Drupal.attachBehaviors(reply);
											if (data.mode === 'flat') {
												var replies = form.parents('.teaser-comments');
												reply.hide().fadeIn();
											} else { // threaded
												var replies = form.parents('.teaser-comment').next('div.indented');
												if (replies.length == 0) {
													replies = $('<div class="indented">');
													form.parents('.teaser-comment').after(replies.hide().fadeIn());
												} else {
													reply.hide().fadeIn();
												}
											}
											replies.append(reply);
											var w = $(window);
											var offtop = reply.offset().top
											if (offtop > w.scrollTop() + w.height()) {
												$('html,body').animate({'scrollTop': offtop - w.height() / 2});
											}
											form.find('textarea').val('');
											tcrf.slideUp('fast', function() { tc.removeClass('replying'); });
										} else {
											form.find('textarea').parent().addClass('error').append('<div class="error-message">' + data.body + '</div>');
										}
									},
								error: function(xmlReq, status, error){
									},
								complete:function(xmlReq, status){
									}
								});
							return false;
						}).end()
					.find('a.teaser-comment-write-comment-cancel').bind('click',
						function() {
							tcrf.slideUp('fast', function() { tc.removeClass('replying'); });
							return false;
						});
				});
		}
		bindTeaserReply($('.teaser-comment', context));
		function bindTeaserEdit(elems) {
			$.each(elems, function(i,o) {
				var tc = $(o);
				var comment = tc.find('.comment-content');
				var tcef = tc.find('.teaser-comment-edit-form');
				tc.find('a.teaser-comment-edit').bind('click', function() {
					comment.hide();
					tcef.show().find('textarea').focus();
					tc.addClass('editing');
					return false;
					});
				tcef.find('form').bind('submit',
						function() {
							var form = $(this);
							$('.error', form).removeClass('error').find('.error-message').remove();
							
							$.ajax({
								url: form.attr('action'),
								type: 'post',
								data: form.serialize(),
								dataType: 'json',
								success: function(data, status, xmlReq) {
									if (data.success) {
										comment.html(data.body);
										comment.show();
										tcef.hide();
										tc.removeClass('editing');
									} else {
										form.find('textarea').parent().addClass('error').append('<div class="error-message">' + data.body + '</div>');
									}
									},
								error: function(xmlReq, status, error) {
									},
								complete: function() {
									}
								});
								
							return false;
						}
					).find('a.teaser-comment-edit-comment-cancel').bind('click',
						function() {
							comment.show();
							tcef.hide();
							tc.removeClass('editing');
 							tcef.find('form')[0].reset();
							return false;
						}
					);
			});
		}
		bindTeaserEdit($('.teaser-comment', context));
		$('a.teaser-comment-show-hidden', context).bind('click',
			function() {
				var $this = $(this);
				$this.append('<span class="throbber busy">');
				$.get(
					$this.attr('href'),
					function(data, status, xmlHttpReq) {
						var contain = $this.hide().next('.teaser-comments');
						contain.html(data);
						Drupal.attachBehaviors(contain);
						var w = $(window);
						var ntop = contain.parents('.node').offset().top;
						if (ntop + contain.height() > w.scrollTop() + w.height()) {
							$('html,body').animate({'scrollTop': ntop - 25});
						}
					}, 'html');
				return false;
			});
		
		$('.teaser-comment-form a.teaser-comment-write-comment', context).bind('click',
			function() {
				$(this).hide().next('form').slideDown('fast').find('textarea').focus();
				return false;
			});
		$('.teaser-comment-form a.teaser-comment-write-comment-cancel', context).bind('click',
			function() {
				$(this).parents('form').slideUp('fast').prev().fadeIn('fast');
				return false;
			});
		$('.teaser-comment-form form', context).submit(
			function() {
				var form = $(this);
				$('.error', form).removeClass('error').find('.error-message').remove();
				$.ajax({
					url: form.attr('action'),
					type: 'post',
					data: form.serialize(),
					dataType: 'json',
					success: function(data, status, xmlReq){
							if (data.success) {
								var comment = $(data.body);
								Drupal.attachBehaviors(comment);
								var comments = form.parents('.teaser-comments-container').find('.teaser-comments');
								if (comments.length == 0) {
									comments = $('<div class="teaser-comments">').hide().fadeIn().prependTo(form.parents('.teaser-comments-container'));
								} else {
									comment.hide().fadeIn();
								}
								comments.append(comment);
								form.find('textarea').val('').end().slideUp('fast').prev().fadeIn('fast');
							} else {
								form.find('textarea').parent().addClass('error').append('<div class="error-message">' + data.body + '</div>');
							}
						},
					error: function(xmlReq, status, error){
						},
					complete:function(xmlReq, status){
						}
					});
				return false;
			});
	};