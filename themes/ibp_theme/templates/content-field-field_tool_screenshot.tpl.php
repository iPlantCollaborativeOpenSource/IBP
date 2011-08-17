<?php
// $Id: content-field.tpl.php,v 1.1.2.6 2009/09/11 09:20:37 markuspetrux Exp $

/**
 * @file content-field.tpl.php
 * Default theme implementation to display the value of a field.
 *
 * Available variables:
 * - $node: The node object.
 * - $field: The field array.
 * - $items: An array of values for each item in the field array.
 * - $teaser: Whether this is displayed as a teaser.
 * - $page: Whether this is displayed as a page.
 * - $field_name: The field name.
 * - $field_type: The field type.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $label: The item label.
 * - $label_display: Position of label display, inline, above, or hidden.
 * - $field_empty: Whether the field has any valid value.
 *
 * Each $item in $items contains:
 * - 'view' - the themed view for that item
 *
 * @see template_preprocess_content_field()
 */
?>
<?php if (!$field_empty) : ?>
<div class="field field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
	<?php if ($items[0]['default']) { ?>
		<?php print $items[0]['view'] ?>
	<?php } else { ?>
		<?php
			foreach ($items as $delta => $item) {
				if (!$item['empty']) {
					$zoomurl = imagecache_create_url('tool_screenshot_zoom', $item['filepath']);
					$rollclass = "rollover rollover-$delta";
					$rollovers .= "<a href=\"$zoomurl\" rel=\"rollovers-{$node->nid}\" title=\"{$item['data']['description']}\">";
					$rollovers .= theme('imagecache', 'tool_screenshot_preview', $item['filepath'], NULL, NULL, array('class' => $rollclass));
					$rollovers .= "</a>";
					
					$screenshots .= "<a href=\"$zoomurl\" rel=\"screenshots-{$node->nid}\" title=\"{$item['data']['description']}\">";
					$screenshots .= theme('imagecache', 'tool_screenshot_small', $item['filepath']);
					$screenshots .= "</a>";
				}
			}
		?>
		<div class="rollovers">
			<?php print $rollovers; ?>
		</div>
		<div class="screenshots clearfix">
			<?php print $screenshots; ?>
		</div>
	<?php } ?>
</div>
<?php endif; ?>