<?php
/**
 * Copyright (c) 2010, iPlant Collaborative, University of Arizona, Cold Spring Harbor Laboratories, University of Texas at Austin
 * This software is licensed under the CC-GNU GPL version 2.0 or later.
 * License: http://creativecommons.org/licenses/GPL/2.0/
 */
?>
<div class="jit jit-forcedirected">
	<div class="forcedirected-wrapper">
		<div id="<?php echo $options['id']; ?>" class="forcedirected">
		</div>
	</div>
</div>
<script type="text/javascript">
	Drupal.behaviors.jit_forceDirected_<?php echo $options['id']; ?> = function (context) {
		if (! window.jit_forceDirected) {
			window.jit_forceDirected = {};
		}
		if (! window.jit_forceDirected['<?php echo $options['id']; ?>']) {
			window.jit_forceDirected['<?php echo $options['id']; ?>'] = new Drupal.jit.forceDirected(<?php echo json_encode($options); ?>);
	
			<?php if ($json): ?>
				window.jit_forceDirected['<?php echo $options['id']; ?>'].render(<?php echo json_encode($json); ?>);
			<?php endif; ?>
		}
	};
</script>