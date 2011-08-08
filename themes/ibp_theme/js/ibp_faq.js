Drupal.behaviors.ibp_faq = function(context) {
	var headers = $('.faq-qa-header').remove();
	var qas_top = $('.faq-qa').remove();
	var qas = $('.faq-category-menu .faq-category-group').remove();
	
	$('.faq').empty();
	
	// categories
	$('<div class="faq-category">').append(headers).appendTo('.faq');
	var pages = $('<div class="faq-category-pages">').appendTo('.faq');
	
	var handler = function() {
		$('.faq-qa-header.selected').removeClass('selected');
		$(this).addClass('selected');
		var index = $(this).data('faq-category-page');
		$('.faq-category-page').hide().eq(index).show();
	}
	
	for (var i = 0; i < qas_top.length; i++) {
		$('<div class="faq-category-page">').append(qas_top[i]).append(qas[i]).appendTo(pages).hide();
		$(headers[i]).data('faq-category-page', i).bind('click', handler);
	}
	
	$('.faq-answer').append('<a class="top-link" href="#">Back to top</a>');
	
	$(headers[0]).trigger('click');
};