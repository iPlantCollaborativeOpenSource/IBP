<div class="newsletter">
	<div class="newsletter_node_body">
		<?php
			print $node->body;
		?>
	</div>
	<div class="newsletter_stories">
		<?php
			print views_embed_view('newsletter','default', $node->nid);
		?>
	</div>
</div>
