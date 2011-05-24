<div class="content ibp_tool">
<h2><?php echo theme($node->title); ?></h2>

<h3>Description</h3>
<p>
<?php print $node->body; ?>
</p>
<dl>
	<dt>Category</dt>
	<dd><?php print $node->field_tool_category[0]['view']; ?></dd>
	<dt>Usability</dt>
	<dd><?php print $node->field_tool_usability[0]['view']; ?></dd>
	<dt>Supported platforms</dt>
	<dd><?php print implode(', ', array_map(function($val) { return $val['view']; }, $node->field_tool_platform)); ?></dd>
	<dt>Version</dt>
	<dd><?php print $node->field_tool_version[0]['view'] ? $node->field_tool_version[0]['view'] : 'n/a'; ?></dd>
	<dt>Download link</dt>
	<dd><?php print l(t('Download link'), $node->field_tool_dl_link[0]['url'], array('attributes' => array('target' => '_blank')))?></dd>
</dl>

<!--
<pre>
<?php
print_r($node);
?>
</pre>
-->

</div>
<div class="clear-block clear"></div>
