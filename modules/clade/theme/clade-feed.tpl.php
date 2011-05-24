<div>
	<table class="no-decor" style="float:right;width:auto;margin-top:-2px;">
		<tr>
			<td style="vertical-align:middle;">
				<?php print t('Include posts from subclades'); ?>:
			</td>
			<td>
				<form class="feed-options">
					<input type="checkbox" name="filter" id="feed-options-filter"/>
				</form>
			</td>
			<td>
				<div class="throbber" style="width:15px;height:15px;"></div>
			</td>
		</tr>
	</table>
	<h2 class="title"><?php print $title; ?></h2>
</div>		
<div>
	<?php if ($mini_form) : ?>
		<?php print $mini_form; ?>
	<?php endif; ?>
	<div class="clade-feed">
		<?php
			if ($feed) {
				print $feed;
			} else {
				print t('There are no posts in this Clade.');
			}
		?>
	</div>
	<div class="centered"><div class="mp-advanced-feed-more"></div></div>
</div>
<script>
	$(document).ready(
		function() {
			Drupal.clade.initFeed(<?php print $clade->tid;?>);
			$('form.feed-options :checkbox').iphoneStyle({
				checkedLabel: 'Yes',
				uncheckedLabel: 'No'
				});
		}
	);
</script>