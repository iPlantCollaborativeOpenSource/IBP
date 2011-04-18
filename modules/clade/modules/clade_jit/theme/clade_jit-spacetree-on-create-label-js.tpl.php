function (label, node) {
	var lbl = jQuery(label);
	lbl.bind('click.spacetree', function() {
			var tx = window.jit_spacetree['<?php echo $tree_id; ?>'].st.canvas.translateOffsetX,
					ty = window.jit_spacetree['<?php echo $tree_id; ?>'].st.canvas.translateOffsetY,
					m = {enable: true, offsetX: tx, offsetY: ty};
			if (window.jit_spacetree['<?php echo $tree_id; ?>'].st.config.orientation == 'bottom' || window.jit_spacetree['<?php echo $tree_id; ?>'].st.config.orientation == 'top') {
				var nh = node.getData('height'),
						ld = window.jit_spacetree['<?php echo $tree_id; ?>'].st.config.levelDistance,
						lh = nh + ld,
						lts = window.jit_spacetree['<?php echo $tree_id; ?>'].st.config.levelsToShow,
						vh = lh * lts + nh;
				
				var adj = -24;
				var levels = node._depth;
				node.eachLevel(1, lts, function(n) {
					levels = n._depth > levels ? n._depth : levels;
					});
				levels = levels - node._depth;
				adj -= vh / 2;
				if (levels == 0) {
					adj += ld;
				} else if (levels == lts) {
					if (node._depth == 0) {
						adj = -adj - ld;
					} else {
						adj = -adj - lh;
					}
				} else {
					adj += levels * lh + nh;
				}
				
				if (window.jit_spacetree['<?php echo $tree_id; ?>'].st.config.orientation == 'bottom') {
					m.offsetY -= adj;
				} else {
					m.offsetY += adj;
				}
			}
			m.offsetX += window.jit_spacetree['<?php echo $tree_id; ?>'].settings.offsetX;
			m.offsetY += window.jit_spacetree['<?php echo $tree_id; ?>'].settings.offsetY;
			window.jit_spacetree['<?php echo $tree_id; ?>'].jitctxt.find('.selected').removeClass('selected');
			lbl.addClass('selected');
			window.jit_spacetree['<?php echo $tree_id; ?>'].st.onClick(node.id, { Move: m });
			if (window.jit_spacetree['<?php echo $tree_id; ?>'].settings['enable_node_info']) {
				window.jit_spacetree['<?php echo $tree_id; ?>'].getNodeInfo(node,
					function() {
						window.jit_spacetree['<?php echo $tree_id; ?>'].moveNodeInfo(function() {
							window.jit_spacetree['<?php echo $tree_id; ?>'].fadeNodeInfo(1.0);
						});
					});
			}
		});
	lbl.width(node.getData('width')).html(node.name);
	if (node.data.active && node.data.active === "0") {
		lbl.addClass('inactive');
	}
	
	var scratch = jQuery('#jit__spacetree__scratch__');
	var testLbl = jQuery('#jit__spacetree__scratch__lbl__');

	// set current classes
	scratch.attr('class', window.jit_spacetree['<?php echo $tree_id; ?>'].jitctxt.attr('class'));
	testLbl.attr('class', 'node').attr('style', '');
	if (jQuery('#' + node.id).hasClass('selected')) {
		testLbl.addClass('selected');
	}
	
	// try to cause line wrap
	testLbl.width(node.getData('width')).html(node.name);
	var h = testLbl.height();
	if (h > node.getData('height')) {
		node.data.$height = h;
		lbl.height(h);
	}
}