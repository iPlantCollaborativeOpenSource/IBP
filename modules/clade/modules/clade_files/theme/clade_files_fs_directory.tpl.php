<div class="item">
	<div class="directory closeddir">
		<?php echo $fs_dir; ?>
		<span class="attribute"><?php echo format_plural($dir_num_files, '1 file', '@count files'); ?></span>
		<?php
			if (! empty($menu)) {
				echo $menu;
			}
		?>
	</div>
	<div class="clearing"></div>
</div>
