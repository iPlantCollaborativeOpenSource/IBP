<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">

	<?php if ($page == 0): ?>
	<h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
	<?php endif; ?>

	<?php if ($terms): ?>
	<div class="terms">
		<?php print $terms; ?>
	</div>
	<?php endif;?>

  <?php if ($node_middle && !$teaser): ?>
  <div id="node-middle">
    <?php print $node_middle; ?>
  </div>
  <?php endif; ?>

  <div class="content">
		<h3>Description</h3>
    <?php print $content ?>
  </div>

  <?php if ($links): ?>
  <div class="links">
    <?php print $links; ?>
  </div>
  <?php endif; ?>

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>

	<!--
	<pre>
	<?php
	//print_r(array_keys(get_defined_vars()));
	//print_r($node);
	?>
	</pre>
	-->
</div>
<div class="clear-block clear"></div>
