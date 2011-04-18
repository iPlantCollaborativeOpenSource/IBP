<div id="clade-files-view-fs">
	<?php if (! empty($parent_dir)) : ?>
		<div class="item">
			<div class="closeddir">
				<?php echo $parent_dir; ?>
			</div>
		</div>
		<div class="clearing"></div>
	<?php endif; ?>
	<?php
		echo $fs_dir;
		echo $fs_dir_contents;
	?>
</div>
