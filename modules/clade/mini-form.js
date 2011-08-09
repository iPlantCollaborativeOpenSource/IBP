Drupal.behaviors.clade_mini_form = function(context) {

	var form = $('form.clade-page-mini-form', context);
	if (form.length > 0) {
		if (form.data('initialized') === undefined) {
		
			var cladesField = $('#edit-taxonomy-1');
			var options = [];
			var selected = [];
			cladesField.find('option').each(function() {
				options.push($(this).text());
				if ($(this).is(":selected")) {
					selected.push($(this).text());
				}
			});
			
			var clades_auto = $('<input type="text" class="form-text required">');
			if (selected.length > 0) clades_auto.val(selected.join(', ') + ', ');
			if (cladesField.hasClass('error')) clades_auto.addClass('error');
			cladesField.after(clades_auto);
			cladesField.hide();
			clades_auto.autocomplete(options, {multiple: true, multipleSeparator: ', ', mustMatch: true, matchContains: true, minChars: 0});
						
			form.find('#edit-ajax').val(true).end();
			var hasError = false;
			if (form.find('.error').length > 0) {
				hasError = true;
				if (form.find('fieldset.group-image-info .error').length == 0) {
					form.find('fieldset.group-image-info').hide();
				}
				if (form.find('fieldset.group-file-info .error').length == 0) {
					form.find('fieldset.group-file-info').hide();
				}
			} else {
				form.find('div.form-item:not(#edit-body-wrapper), #edit-body-wrapper label, input.mini-form-submit, .mini-form-cancel, img.image-button, span.button-value, fieldset.group-image-info, fieldset.group-file-info').hide();
			}
			
			$('#edit-body-wrapper textarea', form).bind('focus', function() {
					form.find('div.form-item, #edit-body-wrapper label, input.mini-form-submit, .mini-form-cancel, img.image-button, span.button-value').fadeIn();
					$(this).attr('rows', 4);
					if (form.height() + form.offset().top > $(window).height()) {
						$("html,body").animate({scrollTop: form.offset().top - 250}, 'slow');
					}
				});
			form.find('.mini-form-cancel').bind('click', function() {
					form.find('.image-button').each(function() {
						var $this = $(this);
						if ($this.next('fieldset').is(':visible')) {
							$this.trigger('click');
						}
					});
					form.find('#edit-title-wrapper input, #edit-body-wrapper textarea').val('');
					form.find('div.form-item:not(#edit-body-wrapper), #edit-body-wrapper label, input.mini-form-submit, .mini-form-cancel, img.image-button, span.button-value').fadeOut('fast');
					form.find('#edit-body-wrapper textarea', form).attr('rows',1);
					form.parents('.clade-page-mini-form-wrapper').find('.messages').fadeOut(function() {$(this).remove()});
					form.find('.error').removeClass('error');
					
					if ($(document).scrollTop() > form.offset().top) {
						$("html,body").animate({scrollTop: form.offset().top - 250}, 'fast');
					}
					
					return false;
				});
			
			form.find('.image-button').bind('click', function() {
				$(this).next('fieldset').slideToggle();
			});
			
			form.bind('submit', function() {
				
				// prevent accidental submission
				if (typeof Drupal.autocompleteSubmit == "function" && ! Drupal.autocompleteSubmit()) {
					return false;
				}
				
				var cladeSelection = clades_auto.val().split(', ');
				cladesField.find('option').removeAttr('selected');
				for (var i = 0; i < cladeSelection.length; i++) {
					if (cladeSelection[i] != '') {
						cladesField.find('option:contains('+cladeSelection[i]+')').attr('selected','selected');
					}
				}
				
				$.ajax({
					url: form.attr('action'),
					type: 'post',
					dataType: 'json',
					data: form.serialize(),
					beforeSend: function() {
						form.parent().find('div.messages').fadeOut(function() {$(this).remove()});
						form.find('.error').removeClass('error');
					},
					success: function(resp) {
						var parent = form.parent();
						parent.prepend($(resp.messages).hide().fadeIn());
						if (resp.valid) {
							var nc = $(resp.new_content);
							$('.clade-feed').prepend(nc);
							Drupal.attachBehaviors(nc);
						}
						var newform = $(resp.form);
						form.replaceWith(newform);
						Drupal.attachBehaviors(parent);
					},
					error: function(xmlr, status, err) {
						//console.log('error: ' + status);
					}
				});
				return false;
			});
			
			function mirrorTitle() {
				$('#edit-body-wrapper textarea', form).bind('keyup keydown keypress paste', function(e) {
						$('#edit-title-wrapper input', form).val($(this).val().substr(0, 60));
					});
				$('#edit-title-wrapper input', form)
						.unbind('blur')
						.bind('keyup keydown keypress paste', unmirrorTitle);
			}
		
			function unmirrorTitle() {
				$('#edit-body-wrapper textarea', form).unbind('keyup keydown keypress paste');
				$('#edit-title-wrapper input', form)
						.unbind('keyup keydown keypress paste')
						.bind('blur', function() {
							if ($('#edit-body-wrapper textarea', form).val().indexOf($(this).val()) == 0) {
								mirrorTitle();
							}
						});
			}
			
			if (hasError) {
				unmirrorTitle();
				$('#edit-title-wrapper input', form).trigger('blur');
			} else {
				mirrorTitle();
			}

			if ($('fieldset.group-image-info').length > 0) {
				var image_optional = $('<fieldset class="collapsible collapsed"><legend>Optional fields</legend></fieldset>');
				$('fieldset.group-image-info').append(image_optional);
				image_optional.append($('#edit-group-image-info-field-description-0-value-wrapper'));
				image_optional.append($('#edit-group-image-info-field-photographer-0-value-wrapper'));
				image_optional.append($('#edit-group-image-info-field-source-0-value-wrapper'));
				image_optional.append($('fieldset.group-image-info fieldset.location'));
			}
			
			form.data('initialized', true);
		}
		
		$('input:file', form).unbind('change').bind('change', function() {
			$(this).next('input').trigger('mousedown');
		});
	} else {
		$('input:file', context).unbind('change').bind('change', function() {
			$(this).next('input').trigger('mousedown');
		});
	}
}
