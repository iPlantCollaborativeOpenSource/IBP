Drupal.behaviors.example_fileversion = function(context) {
	$('a.toggle-version-history', context).bind('click', function() { $(this).next('.example-version-history').slideToggle(); return false;});
};
