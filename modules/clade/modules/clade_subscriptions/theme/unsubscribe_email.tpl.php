<p>
	Dear <?php echo $to ?>,
</p>
<p>
	<?php
		print t('This message is confirmation that you have left the @clade_name Clade.',array('@clade_name'=>$clade_name));
	?>
</p>
<p>
	Sincerely,<br/>
	<?php echo $from ?> 
</p>