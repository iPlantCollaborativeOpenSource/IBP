<p>
	Dear <?php echo $to ?>,
</p>
<p>
	<?php
		print t('You just joined the @clade_name Clade!  Now you can post content to that Clade.  Visit the !homepage_link to start a new conversation with your fellow members!', array('@clade_name' => $clade_name, '!homepage_link' => $homepage_link));
	?>
</p>
<p>
	Sincerely,<br/>
	<?php echo $from ?> 
</p>