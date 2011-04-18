<?php
// $Id$
?>
<?php if (!empty($title)) : ?>
	<h3><?php print $title; ?></h3>
<?php endif; ?>
<div style="position:relative;">
<?php
	$numrows = count($rows);
	for ($i = 0; $i < $numrows; $i++) {
		print $rows[$i];
	}
?>
	<div class="clearing"></div>
</div>
