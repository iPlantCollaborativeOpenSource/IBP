<?php if ($active) { ?>
	<?php if ($welcome) : ?>
		<div class="clade-welcome">
			<?php print $welcome; ?>
		</div>
	<?php endif; ?>
	
	<div class="clade-body">
		<?php if ($new_members) : ?>
			<h2 class="title"><?php print t('New Clade Members'); ?></h2>
			<div class="clade-activity activity">
				<?php print $new_members; ?>
			</div>
		<?php endif; ?>
		
		<?php print $feed; ?>
	</div>

	<div class="clade-footer">
		<?php if (isset($network) || isset($members)) { ?>
		<div class="columns">
			<div class="twothirds">
				<?php if (isset($members)): ?>
					<?php echo $members; ?>
				<?php endif; ?>
				<?php if (isset($network)): ?>
					<?php echo $network; ?>
				<?php endif; ?>
			</div>
			<div class="thirds">
				<div style="padding-left: 12px;">
					<h2 class="title"><?php print t('Posts by Category'); ?></h2>
					<div class="clade-activity activity">
						<?php print $posts_by_category; ?>
					</div>
				</div>
			</div>
			<div class="clearing"></div>
		</div>
		<?php } else { ?>
			<h2 class="title"><?php print t('Posts by Category'); ?></h2>
			<div class="clade-activity activity">
				<?php print $posts_by_category; ?>
			</div>
	<?php } ?>
	</div>
<?php } else { ?>
	<p>
		<?php print t('This clade is not currently active.  Only clades that are active are available to join.  We encourage users that have an interest managing a clade to tell us.'); ?>
	</p>
	<p>
		<?php
			$query = array(
					'name' => $name
				);
			if ($parent) {
				$query['parent_name'] = $parent_name;
			}
			print t('If you would like to join or manage this clade, !link!', array('!link' => l(t('please let us know'), 'support/clade-suggestions', array('query' => $query))));
		?>
	</p>
<?php } ?>