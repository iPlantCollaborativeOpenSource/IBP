<table>
	<tbody>
		<?php $i = 0; ?>
		<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
			<td><strong><?php echo  t('Clade name:'); ?></strong></td>
			<td><?php echo $submission->clade_name; ?></td>
		</tr>
		<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
			<td><strong><?php echo  t('Parent clade name:'); ?></strong></td>
			<td><?php echo $submission->parent_clade_name; ?></td>
		</tr>
		<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
			<td><strong><?php echo  t('Daughter clade name(s):'); ?></strong></td>
			<td>
			<?php
				$daughters = explode(',', $submission->daughter_clade_name);
				foreach ($daughters as $d) :
			?>
				<?php echo trim($d); ?><br/>
			<?php endforeach; ?>
			</td>
		</tr>
		<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
			<td><strong><?php echo  t('Description:'); ?></strong></td>
			<td><?php echo $submission->description; ?></td>
		</tr>
		<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
			<td><strong><?php echo  t('Submitted by:'); ?></strong></td>
			<td><?php echo theme('username', user_load($submission->uid), 0, 1); ?></td>
		</tr>
		<?php if ($link_to_submission || $link_to_voting): ?>
			<?php
				$links = array();
				if ($link_to_submission) {
					$links[] = l(t('View the full submission'), "node/170/submission/$submission->sid"); // Ack!  kludge here again with the webform id
				}
				if ($link_to_voting) {
					$links[] = l(t('View the voting results'), "clade/vote/$submission->id");
				}
			?>
			<tr class="<?php echo $i++%2 == 0 ? 'even' : 'odd'; ?>">
				<td><strong><?php echo  t('More:'); ?></strong></td>
				<td><?php echo theme('item_list', $links, null, 'ul', array('class'=>'no-decoration')); ?></td>
			</tr>
		<?php endif; ?>
	</tbody>
</table>