$(document).ready(function() {
	function getTitle(title, currentArray, currentIndex, currentOpts) {
		$thisImg = currentArray[currentIndex];
		return '<div class="fancybox-title-ibp-float">' + $($thisImg).next().html() + '</div>';
	}
	$('.project-media a').attr("rel","group").fancybox({
		overlayColor:"#000",
		overlayOpacity:0.5,
		titleFormat: getTitle
	});
});