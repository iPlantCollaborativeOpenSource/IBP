<div class="item-level">
	<?php if (! $empty) { ?>
		<?php
			echo $subdirs;
			echo $files;
		?>
	<?php } else { ?>
		<div class="item empty">This folder has no contents.</div>
	<?php } ?>
</div>