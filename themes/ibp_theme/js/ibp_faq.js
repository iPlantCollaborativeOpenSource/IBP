Drupal.behaviors.ibp_faq = function(context) {
	var headers = $('.faq-qa-header').remove();
	var qas_top = $('.faq-qa').remove();
	var qas = $('.faq-category-menu .faq-category-group').remove();
	
	$('.faq').empty();
	
	// categories
	$('<div class="faq-category">').append(headers).appendTo('.faq');
	var pages = $('<div class="faq-category-pages">').appendTo('.faq');
	
	var handler = function(e) {
		$('.faq-qa-header.selected').removeClass('selected');
		$(this).addClass('selected');
		var index = $(this).data('faq-category-page');
		var page = $('.faq-category-page').hide().eq(index);
		var hash = page[0].id;
		window.location.hash = hash;
		page.show();
	}
	
	for (var i = 0; i < qas_top.length; i++) {
		var id = qas[i].id;
		qas[i].id = "";
		$('<div class="faq-category-page">').attr("id",id).append(qas_top[i]).append(qas[i]).appendTo(pages).hide();
		$(headers[i]).data('faq-category-page', i).bind('click', handler);
	}
	
	$('.faq-answer').append('<a class="top-link" href="#">Back to top</a>');
	
	var anchor = window.location.hash;
	if (anchor) {
		var pages = $('.faq-category-page');
		for (var i = 0; i < pages.length; i++) {
			if (anchor == '#'+pages[i].id) {
				setTimeout(function() {$(headers[i]).trigger('click')},250);
				return;
			}
		}
	} else {
		setTimeout(function() {$(headers[0]).trigger('click')},250);
	}
};