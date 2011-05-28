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

	<div class="content ibpbook <?php if($book_navigation_two_col) print "double"?>">
		<div class="col-right">
			<div class="col-left">
				
				<div class="book-navigation-wrapper">
					<?php print $book_navigation ?>
				</div>
			
				<div class="book-content">
					<div class="book-content-wrapper">
					<?php print $content ?>
					</div>
					
					<?php if ($links): ?>
					<div class="links">
						<?php print $links; ?>
					</div>
					<?php endif; ?>

				</div>
				
			</div>  
		</div>
	</div>

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>

</div>
<div class="clear-block clear"></div>
