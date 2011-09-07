Drupal.behaviors.teaser_comments = function(context) {
		function bindTeaserReply(elems) {
			$.each(elems, function() {
				var tc = $(this);
				var tcrf = tc.find('.teaser-comment-reply-form');
				if (! tcrf.hasClass("tc-processed")) {
					tc.find('li.comment_reply a').bind('click',
							function() {
								tc.addClass('replying');
								tcrf.slideDown('fast').find('textarea').focus();
								return false;
							}
						);
					tcrf.find('form input.teaser-comment-comment-submit').bind('click',
							function() {
								var form = $(this).closest('form');
								var formdata = form.serializeArray();
								formdata.push({"name":this.name,"value":this.value});
								$('.error', form).removeClass('error').find('.error-message').remove();
								$.ajax({
									url: form.attr('action'),
									type: 'post',
									data: formdata,
									dataType: 'json',
									success: function(data, status, xmlReq){
											if (data.success) {
												var reply = $("<div>").html(data.body);
												if (data.mode === 'flat') {
													var replies = form.parents('.teaser-comments');
												} else { // threaded
													var replies = form.parents('.teaser-comment').next('div.indented');
													if (replies.length == 0) {
														replies = $('<div class="indented">');
														form.parents('.teaser-comment').after(replies.hide().fadeIn());
													}
												}
												reply.hide().fadeIn();
												if (data.sort == 'oldest') {
													replies.append(reply.html());
												} else {
													replies.prepend(reply.html());
												}
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
					tcrf.addClass("tc-processed");
				}
			});
		}
		bindTeaserReply($('.teaser-comment', context));
		function bindTeaserEdit(elems) {
			$.each(elems, function(i,o) {
				var tc = $(o);
				var tcef = tc.find('.teaser-comment-edit-form');
				if (! tcef.hasClass("tc-processed")) {
					var comment = tc.find('.comment-content');
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
					tcef.find('form input.teaser-comment-comment-submit').bind('click',
							function() {
								var form = $(this).closest('form');
								var formdata = form.serializeArray();
								formdata.push({"name":this.name,"value":this.value});
								$('.error', form).removeClass('error').find('.error-message').remove();
								
								$.ajax({
									url: form.attr('action'),
									type: 'post',
									data: formdata,
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
					tcef.addClass("tc-processed");
				}
			});
		}
		bindTeaserEdit($('.teaser-comment', context));
		
		$('a.teaser-comment-show-hidden:not(.tc-processed)', context).bind('click',
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
			}).addClass('tc-processed');
		
		$('a.teaser-comment-write-comment:not(.tc-processed)', context).bind('click',
			function() {
				$(this).hide().next('div.teaser-comment-form').slideDown('fast').find('textarea').focus();
				return false;
			}).addClass('tc-processed');
		$('div.teaser-comment-form .teaser-comment-write-comment-cancel:not(.tc-processed)', context).bind('click',
			function() {
				$(this).parents('div.teaser-comment-form').slideUp('fast').prev().fadeIn('fast');
				return false;
			}).addClass('tc-processed');
		$('div.teaser-comment-form input.teaser-comment-comment-submit:not(.tc-processed)', context).bind('click',
			function() {
				var form = $(this).closest('form');
				var formdata = form.serializeArray();
				formdata.push({"name":this.name,"value":this.value});
				$('.error', form).removeClass('error').find('.error-message').remove();
				console.log(form.serialize());
				$.ajax({
					url: form.attr('action'),
					type: 'post',
					data: formdata,
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
							if (data.sort == 'oldest') {
								form.closest('.box').before(comment.html());
							} else {
								comments.prepend(comment.html());
								$('body,html').animate({'scrollTop':$('#new').offset().top});
							}
							Drupal.attachBehaviors(comments);
							form.find('textarea').val('').parents('div.teaser-comment-form').slideUp('fast').prev().fadeIn('fast');
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
			}).addClass('tc-processed');
	};