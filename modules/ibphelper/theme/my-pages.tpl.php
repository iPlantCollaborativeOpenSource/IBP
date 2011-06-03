<p>
	The <em>My Pages</em> feature allows you to save pages you find on IBP
	so that you can easily return to those pages later.  You can add a page
	to <em>My Pages</em> by clicking <input type="submit" value="Save to My Pages" class="ibphelper-my-pages-add"/>
	at the top right of any page. You can later remove a page from <em>My Pages</em>
	by visiting the page and clicking <input type="submit" value="Remove from My Pages" class="ibphelper-my-pages-remove"/>.
</p>
<?php if ($mypages) { ?>
	<?php print $mypages; ?>
<?php } else { ?>
	<strong>You have no saved pages.</strong>
<?php } ?>