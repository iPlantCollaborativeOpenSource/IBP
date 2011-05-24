<?php
/**
 * Provides a ctools plugin to display a feed of recent posts for all clades
 * in a panel
 *
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Community feed'),
  'description' => t('A listing of recent posts across all Clades.'),

  'single' => TRUE,
  'content_types' => 'clade_community_feed',
  'render callback' => 'clade_community_feed_content_type_render',

  'edit form' => 'clade_community_feed_content_type_edit_form',
  'admin title' => 'clade_community_feed_content_type_admin_title',
  'admin info' => 'clade_community_feed_content_type_admin_info',

  'icon' => 'icon_example.png',
  'category' => array(t('Clade'), -9),  
);

function clade_community_feed_content_type_admin_title($subtype, $conf, $context = NULL) {
  $output = t('Community feed');
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
function clade_community_feed_content_type_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = 'Community feed';
  $block->content = sprintf(
  		"<dl><dt><strong>Title</strong></dt><dd>%s</dd><dt><strong>Content</strong></dt><dd>A listing of recent posts across all Clades.</dd></dl>",
			$conf['override_title'] ? '<em>Overridden</em> '.$conf['override_title_text'] : 'Community feed'
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
function clade_community_feed_content_type_render($subtype, $conf, $args, $context) {
	global $user;
	if ($user->uid && module_exists('clade_subscriptions') && $user->clades) {
		$title = t('My community feed');
	} else {
		$title = t('Community feed');
	}
	$block = new stdClass();
	$block->title = $conf['override_title'] ? $conf['override_title_text'] : $title;
	$block->content = theme('clade_community_feed', $user);
	return $block;
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function clade_community_feed_content_type_edit_form(&$form, &$form_state) {
  return array();
}
