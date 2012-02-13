Drupal.behaviors.clade_links = function(context) {
	$('.link-delete', context).each(function(i,o) {
		var $this = $(o),
				$linkRow = $this.closest('.link-row'),
				$formItem = $this.closest('.form-item'),
				$deleteLink = $('<a>').attr('href','#').text($this.parent().text()).addClass('delete-link-link'),
				$undoLink = $('<a>').attr('href','#').text('Undo').addClass('undo-link-delete');
		
		$formItem.hide();
		$formItem.parent().append($deleteLink).append($undoLink);
		
		$deleteLink.bind('click', function() {
			$linkRow.addClass('link-row-deleted');
			$this.attr('checked','checked');
			return false;
		});
		
		$undoLink.bind('click', function() {
			$linkRow.removeClass('link-row-deleted');
			$this.attr('checked','');
			return false;
		});
	});
	
	$('a.test').bind('click',function() {
		window.open('http://iplantc.org', "test");
		return false;
	});
};