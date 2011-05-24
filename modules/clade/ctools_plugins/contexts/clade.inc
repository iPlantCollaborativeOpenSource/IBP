<?php
// $Id: simplecontext.inc,v 1.1.2.1 2010/01/29 19:54:02 merlinofchaos Exp $


/**
 * @file
 * Sample ctools context type plugin that shows how to create a context from an arg.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Clade'),
  'description' => t('A Clade object.'),
  'context' => 'clade_context_create_clade',  // func to create context
  'settings form' => 'clade_context_clade_settings_form',
  'settings form validate' => 'clade_context_clade_settings_form_validate',
  'keyword' => 'clade',
  'context name' => 'clade',

  // Provides a list of items which are exposed as keywords.
  'convert list' => 'clade_context_clade_convert_list',
  // Convert keywords into data.
  'convert' => 'clade_context_clade_convert',
);

/**
 * Create a context, either from manual configuration or from an argument on the URL.
 *
 * @param $empty
 *   If true, just return an empty context.
 * @param $data
 *   If from settings form, an array as from a form. If from argument, a string.
 * @param $conf
 *   TRUE if the $data is coming from admin configuration, FALSE if it's from a URL arg.
 *
 * @return
 *   a Context object/
 */
function clade_context_create_clade($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('clade');
  $context->plugin = 'clade';
  if ($empty) {
    return $context;
  }
  
  if ($conf) {
  	$tid = is_array($data) && isset($data['tid']) ? $data['tid'] : (is_object($data) ? $data->tid : 0);
  	$data = clade_load($tid);
	}
	
	if (! empty($data)) {
		$context->data = $data;
		$context->title = $data->name;
		$context->argument = $data->tid;
		
		return $context;
	}
}

function clade_context_clade_settings_form($conf, $external = FALSE) {
  if (empty($conf)) {
    $conf = array(
      'tid' => '',
    );
  }

  $form['clade'] = array(
    '#prefix' => '<div class="no-float">',
    '#suffix' => '</div>',
    '#title' => t('Enter the tid of a Clade'),
    '#type' => 'textfield',
    '#weight' => -10,
  );

  if (!empty($conf['tid'])) {
    $info = db_fetch_object(db_query("SELECT * FROM {term_data} c WHERE c.tid = %d", $conf['tid']));
    if ($info) {
      $link = l(t("'%name' [Clade id %tid]", array('%name' => $info->name, '%tid' => $info->tid)), "clade/$info->tid", array('attributes' => array('target' => '_blank', 'title' => t('Open in new window')), 'html' => TRUE));
      $form['clade']['#description'] = t('Currently set to !link', array('!link' => $link));
    }
  }

  $form['tid'] = array(
    '#type' => 'value',
    '#value' => $conf['tid'],
  );

  return $form;
}

function clade_context_clade_settings_form_validate($form, &$form_values, &$form_state) {
	if (empty($form_values['tid']) && empty($form_values['clade'])) {
    form_error($form['clade'], t('You must select a Clade.'));
    return;
  }

  if (empty($form_values['clade'])) {
    return;
  }

  $tid = $form_values['clade'];

  if (is_numeric($tid)) {
    $clade = db_fetch_object(db_query(db_rewrite_sql("SELECT n.tid FROM {term_data} n WHERE n.tid = %d"), $tid));
		if (! $clade) {
			form_error($form['clade'], t('Invalid Clade tid.'));
		} else {
			form_set_value($form['tid'], $clade->tid, $form_state);
		}
  } else {
    form_error($form['clade'], t('Invalid Clade tid.'));
  }
}

/**
 * Provide a list of sub-keywords.
 *
 * This is used to provide keywords from the context for use in a content type,
 * pane, etc.
 */
function clade_context_clade_convert_list() {
  return array(
    'tid' => t('Clade ID'),
    'name' => t('Clade name'),
    'description' => t('Clade description'),
  );
}

/**
 * Convert a context into a string to be used as a keyword by content types, etc.
 */
function clade_context_clade_convert($context, $type) {
  switch ($type) {
    case 'tid':
      return $context->data->tid;
    case 'name':
      return $context->data->name;
    case 'description':
      return $context->data->description;
  }
}

