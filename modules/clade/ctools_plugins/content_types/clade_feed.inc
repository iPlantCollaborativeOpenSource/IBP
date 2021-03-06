<?php
/**
 * Provides a ctools plugin to display a recent posts for a clade in a panel
 *
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Clade feed'),
  'description' => t('A listing of recent posts in a Clade.'),

  'single' => TRUE,
  'content_types' => 'clade_feed',
	'required context' => new ctools_context_required(t('Clade'), 'clade'),
  'render callback' => 'clade_feed_content_type_render',

  'edit form' => 'clade_feed_content_type_edit_form',
  'admin title' => 'clade_feed_content_type_admin_title',
  'admin info' => 'clade_feed_content_type_admin_info',

  'icon' => 'icon_example.png',
  'category' => array(t('Clade'), -9),  
);

function clade_feed_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Clade feed');
  if ($conf['override_title'] && !empty($conf['override_title_text'])) {
    $output = filter_xss_admin($conf['override_title_text']);
  }
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building
 * a panel).
 *
 * In this case we'll render the content with a dummy argument and
 * a dummy context.
 */
function clade_feed_content_type_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = 'Clade feed';
  $block->content = sprintf(
  		"<dl><dt><strong>Title</strong></dt><dd>%s</dd><dt><strong>Content</strong></dt><dd>A listing of recent posts in a Clade</dd></dl>",
			$conf['override_title'] ? '<em>Overridden</em> '.$conf['override_title_text'] : 'Clade feed'
		);
	return $block;
}

/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   An object with at least title and content members
 */
function clade_feed_content_type_render($subtype, $conf, $args, $context) {
	$clade = $args[0];
	$block = new stdClass();
	if ($clade) {
		$block->title = $conf['override_title'] ? $conf['override_title_text'] : $clade->name;
		$block->content = theme('clade_feed', $clade);
	} else {
		$block->content = 'No Clade';
	}
	return $block;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function clade_feed_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  $form['clade'] = array(
    '#type' => 'textfield',
    '#title' => t('Clade ID for context'),
    '#size' => 50,
    '#description' => t('The Clade tid.'),
    '#default_value' => !empty($conf['clade']) ? $conf['clade'] : '',
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

function clade_feed_content_type_edit_form_submit(&$form, &$form_state) {
	foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}