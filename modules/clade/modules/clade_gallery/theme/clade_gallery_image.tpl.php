<?php if ($teaser) { ?>
	<div class="columns">
		<div class="halfs centered">
			<?php print l(theme('imagecache', 'small', $node->clade_gallery_image[0]['filepath'], $node->clade_gallery_image[0]['data']['alt'], $node->clade_gallery_image[0]['data']['title'] ? $node->clade_gallery_image[0]['data']['title'] : $node->title), $teaser ? "node/$node->nid" : $node->clade_gallery_image[0]['filepath'], array('html'=>true)); ?>
		</div>
		<div class="halfs reduce">
			<div style="margin-left: 6px">
				<?php if ($node->field_description[0]['value']): ?>
					<h4 class="title"><?php print t('Description');?></h4>
					<div><?php print node_teaser($node->field_description[0]['value'], NULL, 200); ?></div>
				<?php endif; ?>
				<?php if ($node->field_photographer[0]['value']): ?>
					<h4 class="title"><strong><?php print t('Photographer/Artist'); ?></strong></h4>
					<div><?php print $node->field_photographer[0]['safe']; ?></div>
				<?php endif; ?>
				<?php if ($node->field_copyright[0]['value']): ?>
					<h4 class="title"><strong><?php print t('Copyright Information'); ?></strong></h4>
					<div><?php print $node->field_copyright[0]['safe']; ?></div>
				<?php endif; ?>
				<?php if ($node->field_source[0]['value']): ?>
					<h4 class="title"><strong><?php print t('Source'); ?></strong></h4>
					<div><?php print $node->field_source[0]['safe']; ?></div>
				<?php endif; ?>
			</div>
		</div>
		<div class="clearing"></div>
	</div>

<?php } else if ($page) { ?>

	<?php print l(theme('imagecache', 'large', $node->clade_gallery_image[0]['filepath'], $node->clade_gallery_image[0]['data']['alt'], $node->clade_gallery_image[0]['data']['title'] ? $node->clade_gallery_image[0]['data']['title'] : $node->title), $teaser ? "node/$node->nid" : $node->clade_gallery_image[0]['filepath'], array('html'=>true)); ?>
	
	<div>
		<p><?php print $node->field_description[0]['value']; ?></p>
	</div>
	
	<div class="columns">
		<div class="halfs">
			<?php if ($node->field_geotag[0]['lid']): ?>
				<h4 class="title">Geotag</h4>
				<div><?php print $node->field_geotag[0]['view']; ?></div>
			<?php endif; ?>
		</div>
		<div class="halfs">
			<?php if ($node->field_photographer[0]['value']): ?>
				<h4 class="title"><strong><?php print t('Photographer/Artist'); ?></strong></h4>
				<div><?php print $node->field_photographer[0]['safe']; ?></div>
			<?php endif; ?>
			<?php if ($node->field_copyright[0]['value']): ?>
				<h4 class="title"><strong><?php print t('Copyright Information'); ?></strong></h4>
				<div><?php print $node->field_copyright[0]['safe']; ?></div>
			<?php endif; ?>
			<?php if ($node->field_source[0]['value']): ?>
				<h4 class="title"><strong><?php print t('Source'); ?></strong></h4>
				<div><?php print $node->field_source[0]['safe']; ?></div>
			<?php endif; ?>
		</div>
		<div class="clearing" style="height: 1em;"></div>
	</div>

<?php } else { ?>

	<?php print l(theme('imagecache', 'small', $node->clade_gallery_image[0]['filepath'], $node->clade_gallery_image[0]['data']['alt'], $node->clade_gallery_image[0]['data']['title'] ? $node->clade_gallery_image[0]['data']['title'] : $node->title), $teaser ? "node/$node->nid" : $node->clade_gallery_image[0]['filepath'], array('html'=>true)); ?>

<?php } ?>