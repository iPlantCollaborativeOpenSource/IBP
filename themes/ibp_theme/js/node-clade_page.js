$(document).ready(function() {
	function cladePageImageTitle(title, currentArray, currentIndex, currentOpts) {
		$thisImg = currentArray[currentIndex];
		return '<div class="fancybox-title-ibp-float">' + $($thisImg).next().html() + '</div>';
	}
	$('.clade-page-image a').fancybox({
		overlayColor:"#000",
		overlayOpacity:0.5,
		titleFormat:cladePageImageTitle
	});
});