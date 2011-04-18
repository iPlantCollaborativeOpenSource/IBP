<?php
/**
 * Provides a ctools plugin to display a spacetree visualization of clades in a panel
 */
 /**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Clade JIT Spacetree content type'),
  'description' => t('Clade JIT Spacetree content type - works with a clade_jit_spacetree_start_node context.'),

  'single' => TRUE,
  'content_types' => array('clade_jit_spacetree_content_type'),
  'render callback' => 'clade_jit_spacetree_content_type_render',
  'defaults' => array('clade_jit_spacetree_start_node' => 0),

  'edit form' => 'clade_jit_spacetree_content_type_edit_form',
  'admin title' => 'clade_jit_clade_jit_spacetree_content_type_admin_title',
  'admin info' => 'clade_jit_clade_jit_spacetree_content_type_admin_info',

  'icon' => 'icon_example.png',
  'category' => array(t('Clade'), -9),  
);

function clade_jit_clade_jit_spacetree_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Clade JIT Spacetree');
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
function clade_jit_clade_jit_spacetree_content_type_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = 'Clade JIT Spacetree';
  $block->content = sprintf("<dl><dt><strong>Override Title</strong></dt><dd>%s</dd><dt><strong>Start Node</strong></dt><dd>%s</dd></dl>",
			$conf['override_title'] ? $conf['override_title_text'] : 'Default',
			$conf['clade_jit_spacetree_start_node'] ? sprintf('Start Node NID: %s', $conf['clade_jit_spacetree_start_node']) : 'Root'
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
function clade_jit_spacetree_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
	
  $block->title = $conf['override_title'] ? $conf['override_title_text'] : 'Clade JIT Spacetree';
  
  $options = array();
  $options['id'] = uniqid('clade_jit_st_');
	$options['after'] = sprintf("<div class='asterisk'>%s</div>",
		t('Note: this tree diagram is only intended to show the hierarchical structure of the My-Plant social network. It is not meant to represent the full phylogeny of green plants. Want to see additional clades?  !link', array('!link' => l(t('You can help it grow!'), 'support/clade-suggestions')))
		);
  $block->content = clade_jit_spacetree($conf['clade_jit_spacetree_start_node'], $options);
  
  return $block;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function clade_jit_spacetree_content_type_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  $form['clade_jit_spacetree_start_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Node ID for spacetree initially selected node.'),
    '#size' => 50,
    '#description' => t('The node id.  Enter "0" for the root node.'),
    '#default_value' => $conf['clade_jit_spacetree_start_node'],
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

function clade_jit_spacetree_content_type_edit_form_submit(&$form, &$form_state) {
	if (!empty($form_state['values']['clade_jit_spacetree_start_node'])) {
		$form_state['conf']['clade_jit_spacetree_start_node'] = $form_state['values']['clade_jit_spacetree_start_node'];
	} else {
		$form_state['conf']['clade_jit_spacetree_start_node'] = 0;
	}
}