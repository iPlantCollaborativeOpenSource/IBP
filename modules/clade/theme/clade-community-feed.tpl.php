<?php if ($title): ?>
<h2 class="title"><?php print $title; ?></h2>
<?php endif; ?>
<div>
	<?php if ($mini_form) : ?>
		<?php print $mini_form; ?>
	<?php endif; ?>
	<div class="clade-feed">
		<?php
			if ($feed) {
				print $feed;
			} else {
				if ($user->uid) {
					print t('No activity to show!  Why don\'t you post something?');
				} else {
					print t('No activity to show!');
				}
			}
		?>
	</div>
	<div class="centered"><div class="mp-advanced-feed-more"></div></div>
</div>

<script>$(document).ready(function() { Drupal.clade.communityFeed(); });</script>