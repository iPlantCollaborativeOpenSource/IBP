Drupal.behaviors.fileversion_fileversionList = function(context) {
	$('a.toggle-version-history', context).bind('click', function() { $(this).next('.fileversion-version-history').slideToggle(); return false;});
};