<?php
/**
 * Provides a ctools plugin to display a force directed visualization of clades in a panel
 *
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Clade JIT Force Directed content type'),
  'description' => t('Clade JIT Force Directed content type.'),

  'single' => TRUE,
  'content_types' => array('clade_jit_forcedirected'),
  'render callback' => 'clade_jit_forcedirected_content_type_render',
  'defaults' => array(),

  'edit form' => 'clade_jit_forcedirected_content_type_edit_form',
  'admin title' => 'clade_jit_clade_jit_forcedirected_content_type_admin_title',
  'admin info' => 'clade_jit_clade_jit_forcedirected_content_type_admin_info',

  'icon' => 'icon_example.png',
  'category' => array(t('Clade'), -9),  
);

function clade_jit_clade_jit_forcedirected_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Clade JIT Force Directed');
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
function clade_jit_clade_jit_forcedirected_content_type_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = 'Clade JIT Force Directed';
  $block->content = sprintf("<dl><dt><strong>Override Title</strong></dt><dd>%s</dd></dl>",
			$conf['override_title'] ? $conf['override_title_text'] : 'Clade JIT Force Directed'
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
function clade_jit_forcedirected_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
	
  $block->title = $conf['override_title'] ? $conf['override_title_text'] : 'Clade JIT Force Directed';
  
  $options = array();
  $options['id'] = uniqid('clade_jit_fd_');
  $block->content = clade_jit_forcedirected($options);
  
  return $block;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function clade_jit_forcedirected_content_type_edit_form(&$form, &$form_state) {
  return array();
}

function clade_jit_forcedirected_content_type_edit_form_submit(&$form, &$form_state) {
}