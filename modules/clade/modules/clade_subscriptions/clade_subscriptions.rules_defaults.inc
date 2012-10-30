<?php
/**
 * Default rules config
 */

function clade_subscriptions_rules_defaults() {
	$rules = array();
	
	$condition = rules_use_condition('clade_subscriptions_node_is_clade_content_type', array('#setting' => array(
		'#argument map' => array('node' => 'node'),
	)));
	
	// new content notifications
	$templatePath = drupal_get_path('module', 'clade_subscriptions').'/templates/new_content_notification.inc';
	$actions = array(
		rules_use_action('clade_subscriptions_send_new_content_notification', array('#settings' => array(
			'subject' => 'New in [node:clade-name]: [node:title]',
			'message' => file_get_contents($templatePath),
			'#argument map' => array(
				'node' => 'node',
			),
			'#eval input' => array(
				'token_rules_input_evaluator' => array(
					'subject' => array('node'),
					'message' => array('node','author',':global'),
				),
				'rules_input_evaluator_php' => array(
					'message' => array('node'),
				),
			),
		))),
	);
	$rules['clade_subscriptions_new'] = array(
    '#type' => 'rule',
    '#name' => 'clade_subscriptions_new',
    '#set' => 'event_node_insert',
    '#label' => t('Send notification of new content to subscribed members of a Clade.'),
    '#active' => TRUE,
    '#status' => 'default',
    '#conditions' => array($condition),
    '#actions' => $actions,
    '#categories' => array('clade'),
  );
	
	// updated content notifications
	$templatePath = drupal_get_path('module', 'clade_subscriptions').'/templates/update_notification.inc';
	$actions = array(
		rules_use_action('clade_subscriptions_send_update_notification', array('#settings' => array(
			'subject' => 'Updated in [node:clade-name]: [node:title]',
			'message' => file_get_contents($templatePath),
			'#argument map' => array(
				'node' => 'node',
			),
			'#eval input' => array(
				'token_rules_input_evaluator' => array(
					'subject' => array('node'),
					'message' => array('node','user',':global'),
				),
				'rules_input_evaluator_php' => array(
					'message' => array('node'),
				),
			),
		))),
	);
	$rules['clade_subscriptions_updated'] = array(
    '#type' => 'rule',
    '#name' => 'clade_subscriptions_updated',
    '#set' => 'event_node_update',
    '#label' => t('Send notification of updated content to subscribed members of a Clade.'),
    '#active' => TRUE,
    '#status' => 'default',
    '#conditions' => array($condition),
    '#actions' => $actions,
		'#categories' => array('clade'),
 );
	
	// new comment notifications
	$templatePath = drupal_get_path('module', 'clade_subscriptions').'/templates/comment_notification.inc';
	$actions = array(
		rules_use_action('clade_subscriptions_send_new_content_notification', array('#settings' => array(
			'subject' => 'New comment in [node:clade-name]: [node:title]',
			'message' => file_get_contents($templatePath),
			'#argument map' => array(
				'node' => 'node',
				'comment' => 'comment',
			),
			'#eval input' => array(
				'token_rules_input_evaluator' => array(
					'subject' => array('node'),
					'message' => array('comment_author','comment','node','node_author',':global'),
				),
				'rules_input_evaluator_php' => array(
					'message' => array('node'),
				),
			),
		))),
	);
	$rules['clade_subscriptions_comment'] = array(
    '#type' => 'rule',
    '#name' => 'clade_subscriptions_comment',
    '#set' => 'event_comment_insert',
    '#label' => t('Send notification of new comments to subscribed members of a Clade.'),
    '#active' => TRUE,
    '#status' => 'default',
    '#conditions' => array($condition),
    '#actions' => $actions,
		'#categories' => array('clade'),
  );
  
  return array('rules' => $rules);
}