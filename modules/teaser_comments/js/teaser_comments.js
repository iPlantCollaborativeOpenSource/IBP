Drupal.behaviors.teaser_comments = function(context) {
		function bindTeaserReply(elems) {
			$.each(elems, function() {
				var tc = $(this);
				if (! tc.hasClass("tcreply-processed")) {
					var tcrf = tc.find('.teaser-comment-reply-form');
					tc.find('li.comment_reply a').bind('click',
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
												var reply = $("<div>").html(data.body);
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
												replies.append(reply.html());
												Drupal.attachBehaviors(replies);
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
						.find('.teaser-comment-write-comment-cancel').bind('click',
							function() {
								tcrf.slideUp('fast', function() { tc.removeClass('replying'); });
								return false;
							});
					tc.addClass("tcreply-processed");
				}
			});
		}
		bindTeaserReply($('.teaser-comment', context));
		function bindTeaserEdit(elems) {
			$.each(elems, function(i,o) {
				var tc = $(o);
				if (! tc.hasClass("tcedit-processed")) {
					var comment = tc.find('.comment-content');
					var tcef = tc.find('.teaser-comment-edit-form');
					tc.find('li.comment_edit a').bind('click', function() {
						comment.hide();
						tcef.show().find('textarea').focus();
						tc.addClass('editing');
						return false;
						});
					tcef.find('.teaser-comment-edit-comment-cancel').bind('click',
							function(e) {
								e.stopPropagation();
								comment.show();
								tcef.hide();
								tc.removeClass('editing');
								tcef.find('form')[0].reset();
								return false;
							}
						);
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
						);
					tc.addClass("tcedit-processed");
				}
			});
		}
		bindTeaserEdit($('.teaser-comment', context));
		
		$('a.teaser-comment-show-hidden', context).bind('click',
			function() {
				var comments = $(this).fadeOut().next('.teaser-comments');
				comments.find('.teaser-comment.hidden').slideDown();
				setTimeout(
					function() {
						var w = $(window);
						var ntop = comments.parent().offset().top;
						if (ntop + comments.height() > w.scrollTop() + w.height()) {
							var fudge = 25 + comments.parent().prev().height();
							$('html, body').animate({'scrollTop': ntop - fudge});
						}
					},400);
				return false;
			});
		
		$('a.teaser-comment-write-comment', context).bind('click',
			function() {
				$(this).hide().next('div.teaser-comment-form').slideDown('fast').find('textarea').focus();
				return false;
			});
		$('div.teaser-comment-form .teaser-comment-write-comment-cancel', context).bind('click',
			function() {
				$(this).parents('div.teaser-comment-form').slideUp('fast').prev().fadeIn('fast');
				return false;
			});
		$('form[id^=comment-form]', context).bind('submit',
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
								var comment = $("<div>").html(data.body);
								var comments = form.parents('.teaser-comments-container').find('.teaser-comments');
								if (comments.length == 0) {
									comments = $('<div class="teaser-comments">').hide().fadeIn().prependTo(form.parents('.teaser-comments-container'));
								} else {
									comment.hide().fadeIn();
								}
								comments.append(comment.html());
								Drupal.attachBehaviors(comments);
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