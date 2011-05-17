<div class="content ibp_tool">
<h2><?php echo theme($node->title); ?></h2>
<table>
<tr><th>Name</th><th>Description</th><th>Platform</th><th>Link</th></tr>
<tr>
	<td><?php echo $node->title; ?></td>
	<td><div class="pane-content"><p><?php echo $node->field_tool_description[0]['view']; ?></p></div></td>
	<td>
		<?php 
			$html = "Available Platforms: ";
			foreach($node->field_tool_platform as $platform) {
				$html .= " " . $platform['view'];
			}
			echo $html;
		?>
	</td>
	<td><?php echo l(t("Download Link"), $node->field_tool_dl_link[0]['url'], array('attributes' => array('target' => '_blank'))); ?></td></tr>
</table>
<pre>
<?php
print_r($node);
?>
</pre>
</div>
<div class="clear-block clear"></div>
