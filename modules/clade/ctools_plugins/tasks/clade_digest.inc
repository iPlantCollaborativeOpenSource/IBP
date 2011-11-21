<?php
// $Id$
function clade_clade_digest_page_manager_tasks() {
	return array(
		// This is a 'page' task and will fall under the page admin UI
		'task type' => 'page',
	 
		'title' => t('Clade digest'),
		'admin title' => t('Clade digest'),
		'admin description' => t('When enabled, this provides a page with summary views for Clade content.'),
		'admin path' => 'clade/%clade/digest',
		'admin summary' => 'clade_digest_admin_summary',
	 
		// Menu hooks
		'hook menu' => 'clade_digest_menu',
	 
		// This task provides the 'clade' context to content-types on the panel
		'handler type' => 'context',
		'get arguments' => 'clade_digest_get_arguments',
		'get context placeholders' => 'clade_digest_get_contexts',
	 
		// Allow this panel-page to be enabled or disabled:
		'disabled' => variable_get('clade_digest_disabled', TRUE),
		'enable callback' => 'clade_digest_enable',
		'default handlers' => clade_clade_digest_default_handlers(),
	);
}

function clade_digest_menu(&$items, $task) {
  // the enable/disable callback will set a variable to control whether the panel is enabled.
  if (variable_get('clade_digest_disabled', TRUE)) {
    // the panel is disabled: don't run the menu-alter, leave the default menu entry.
    return;
  }
  
  $items['clade/%clade/digest'] = array(
  	'title' => 'Clade digest',
  	'page callback' => 'clade_digest_page',
  	'page arguments' => array(1),
  	'access callback' => 'clade_homepage_access',
		'access arguments' => array(1,'access content'),
  	'file path' => $task['path'],
  	'file' => $task['file'],
  	'type' => MENU_LOCAL_TASK,
  	'weight' => 1,
  );
}

function clade_digest_enable($cache, $status) {
  variable_set('clade_digest_disabled', $status);
}

function clade_digest_get_arguments($task, $subtask_id) {
  return array(
		array(
      'keyword' => 'clade',
      'identifier' => t('Clade'),
      'id' => 1,
      'name' => 'clade',
    ),
  );
}
 
/**
 * Callback to get context placeholders provided by this handler.
 */
function clade_digest_get_contexts($task, $subtask_id) {
  $context = ctools_context_get_placeholders_from_argument(clade_digest_get_arguments($task, $subtask_id));
  return $context;
}

function clade_digest_page($clade) {
	// Load my task plugin
	$task = page_manager_get_task('clade_digest');
	// Load the clade into a context.
	ctools_include('context');
	ctools_include('context-task-handler');
	$contexts = ctools_context_handler_get_task_contexts($task, '', array($clade));
	
	$output = ctools_context_handler_render($task, '', $contexts, array($clade));
	if ($output !== FALSE) {
		return $output;
	}
	
	// Otherwise, fall back.
	module_load_include('inc', 'taxonomy', 'taxonomy.pages');
	return taxonomy_term_page($clade->tid);
}

function clade_digest_admin_summary($task, $subtask) {
  $task_name = page_manager_make_task_name($task['name'], $subtask['name']);

  $rows[] = array(
    array('class' => t('page-summary-label'), 'data' => t('Path')),
    array('class' => t('page-summary-data'), 'data' => 'clade/%clade/digest'),
    array('class' => t('page-summary-operation'), 'data' => ''),
  );

  $rows[] = array(
    array('class' => t('page-summary-label'), 'data' => t('Access')),
    array('class' => t('page-summary-data'), 'data' => t('This page is publicly accessible.')),
    array('class' => t('page-summary-operation'), 'data' => ''),
  );

  $menu = t('No menu entry');

  $rows[] = array(
    array('class' => t('page-summary-label'), 'data' => t('Menu')),
    array('class' => t('page-summary-data'), 'data' => $menu),
    array('class' => t('page-summary-operation'), 'data' => ''),
  );

  $rows[] = array(
    array('class' => t('page-summary-label'), 'data' => t('%clade')),
    array('class' => t('page-summary-data'), 'data' => t('The Clade id.')),
    array('class' => t('page-summary-operation'), 'data' => ''),
  );

  $output = theme('table', array(), $rows, array('id' => 'page-manager-page-summary'));
  return $output;
}

function clade_clade_digest_default_handlers() {
	$handlers = array();
	
// 	$handler = new stdClass;
// 	$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
// 	$handler->api_version = 1;
// 	$handler->name = 'clade_digest_panel_context';
// 	$handler->task = 'clade_digest';
// 	$handler->subtask = '';
// 	$handler->handler = 'panel_context';
// 	$handler->weight = 0;
// 	$handler->conf = array(
// 		'title' => 'Clade panel',
// 		'no_blocks' => 0,
// 		'pipeline' => 'standard',
// 		'css_id' => '',
// 		'css' => '',
// 		'contexts' => array(),
// 		'relationships' => array(),
// 	);
// 	$display = new panels_display;
// 	$display->layout = 'twocol_bricks';
// 	$display->layout_settings = array();
// 	$display->panel_settings = array(
// 		'style_settings' => array(
// 			'default' => NULL,
// 			'top' => NULL,
// 			'left_above' => NULL,
// 			'right_above' => NULL,
// 			'middle' => NULL,
// 			'left_below' => NULL,
// 			'right_below' => NULL,
// 			'bottom' => NULL,
// 		),
// 	);
// 	$display->cache = array();
// 	$display->title = '';
// 	$display->content = array();
// 	$display->panels = array();
// 		$pane = new stdClass;
// 		$pane->pid = 'new-1';
// 		$pane->panel = 'left_below';
// 		$pane->type = 'clade_jit_forcedirected';
// 		$pane->subtype = 'clade_jit_forcedirected';
// 		$pane->shown = TRUE;
// 		$pane->access = array();
// 		$pane->configuration = array(
// 			'override_title' => 0,
// 			'override_title_text' => '',
// 		);
// 		$pane->cache = array();
// 		$pane->style = array(
// 			'settings' => NULL,
// 		);
// 		$pane->css = array();
// 		$pane->extras = array();
// 		$pane->position = 0;
// 		$display->content['new-1'] = $pane;
// 		$display->panels['left_below'][0] = 'new-1';
// 		$pane = new stdClass;
// 		$pane->pid = 'new-2';
// 		$pane->panel = 'middle';
// 		$pane->type = 'clade_feed';
// 		$pane->subtype = 'clade_feed';
// 		$pane->shown = TRUE;
// 		$pane->access = array();
// 		$pane->configuration = array(
// 			'context' => 'argument_clade_1',
// 			'form_build_id' => 'form-706dc20e7c2e660e853d54cf44fcf6c9',
// 			'form_token' => '916ffbd9875989d37018932c9f08d117',
// 			'form_id' => 'clade_feed_content_type_edit_form',
// 			'override_title' => 0,
// 			'override_title_text' => '',
// 		);
// 		$pane->cache = array();
// 		$pane->style = array(
// 			'settings' => NULL,
// 		);
// 		$pane->css = array();
// 		$pane->extras = array();
// 		$pane->position = 0;
// 		$display->content['new-2'] = $pane;
// 		$display->panels['middle'][0] = 'new-2';
// 		$pane = new stdClass;
// 		$pane->pid = 'new-3';
// 		$pane->panel = 'right_below';
// 		$pane->type = 'views_panes';
// 		$pane->subtype = 'clade_posts_by_category-panel_pane_1';
// 		$pane->shown = TRUE;
// 		$pane->access = array();
// 		$pane->configuration = array(
// 			'context' => array(
// 				0 => 'argument_clade_1',
// 			),
// 		);
// 		$pane->cache = array();
// 		$pane->style = array(
// 			'settings' => NULL,
// 		);
// 		$pane->css = array();
// 		$pane->extras = array();
// 		$pane->position = 0;
// 		$display->content['new-3'] = $pane;
// 		$display->panels['right_below'][0] = 'new-3';
// 		$pane = new stdClass;
// 		$pane->pid = 'new-4';
// 		$pane->panel = 'right_below';
// 		$pane->type = 'views_panes';
// 		$pane->subtype = 'clade_archive-panel_pane_1';
// 		$pane->shown = TRUE;
// 		$pane->access = array();
// 		$pane->configuration = array(
// 			'context' => array(
// 				0 => 'argument_clade_1',
// 			),
// 		);
// 		$pane->cache = array();
// 		$pane->style = array(
// 			'settings' => NULL,
// 		);
// 		$pane->css = array();
// 		$pane->extras = array();
// 		$pane->position = 1;
// 		$display->content['new-4'] = $pane;
// 		$display->panels['right_below'][1] = 'new-4';
// 		$pane = new stdClass;
// 		$pane->pid = 'new-5';
// 		$pane->panel = 'top';
// 		$pane->type = 'custom';
// 		$pane->subtype = 'custom';
// 		$pane->shown = TRUE;
// 		$pane->access = array();
// 		$pane->configuration = array(
// 			'admin_title' => 'Clade description',
// 			'title' => '',
// 			'body' => '%clade:description',
// 			'format' => '1',
// 			'substitute' => 1,
// 		);
// 		$pane->cache = array();
// 		$pane->style = array(
// 			'settings' => NULL,
// 		);
// 		$pane->css = array();
// 		$pane->extras = array();
// 		$pane->position = 0;
// 		$display->content['new-5'] = $pane;
// 		$display->panels['top'][0] = 'new-5';
// 	$display->hide_title = PANELS_TITLE_FIXED;
// 	$display->title_pane = 'new-5';
// 	$handler->conf['display'] = $display;
// 
// 	$handlers[$handler->name] = $handler;
	
	$handler = new stdClass;
	$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
	$handler->api_version = 1;
	$handler->name = 'clade_digest_alt_panel_context';
	$handler->task = 'clade_digest_alt';
	$handler->subtask = '';
	$handler->handler = 'panel_context';
	$handler->weight = 0;
	$handler->conf = array(
		'title' => 'Clade digest panel',
		'no_blocks' => 0,
		'pipeline' => 'standard',
		'css_id' => '',
		'css' => '',
		'contexts' => array(),
		'relationships' => array(),
	);
	$display = new panels_display;
	$display->layout = 'twocol_bricks';
	$display->layout_settings = array();
	$display->panel_settings = array(
		'style_settings' => array(
			'default' => NULL,
			'top' => NULL,
			'left_above' => NULL,
			'right_above' => NULL,
			'middle' => NULL,
			'left_below' => NULL,
			'right_below' => NULL,
			'bottom' => NULL,
		),
	);
	$display->cache = array();
	$display->title = '';
	$display->content = array();
	$display->panels = array();
	$pane = new stdClass;
	$pane->pid = 'new-1';
	$pane->panel = 'middle';
	$pane->type = 'views_panes';
	$pane->subtype = 'clade_forum_summary-panel_pane_1';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
		'context' => array(
			0 => 'argument_clade_1',
		),
	);
	$pane->cache = array();
	$pane->style = array(
		'settings' => NULL,
	);
	$pane->css = array();
	$pane->extras = array();
	$pane->position = 0;
	$display->content['new-1'] = $pane;
	$display->panels['middle'][0] = 'new-1';

	$pane = new stdClass;
	$pane->pid = 'new-2';
	$pane->panel = 'middle';
	$pane->type = 'views_panes';
	$pane->subtype = 'clade_post_summary-panel_pane_1';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
		'context' => array(
			0 => 'argument_clade_1',
		),
	);
	$pane->cache = array();
	$pane->style = array(
		'settings' => NULL,
	);
	$pane->css = array();
	$pane->extras = array();
	$pane->position = 1;
	$display->content['new-2'] = $pane;
	$display->panels['middle'][1] = 'new-2';
		
	$display->hide_title = PANELS_TITLE_FIXED;
	$display->title_pane = 'new-4';
	$handler->conf['display'] = $display;

	$handlers[$handler->name] = $handler;
	
	return $handlers;
}