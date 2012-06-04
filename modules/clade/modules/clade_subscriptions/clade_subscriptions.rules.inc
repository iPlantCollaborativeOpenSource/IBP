<?php
/**
 * Rules configuration for clade_subscriptions
 */

function clade_subscriptions_rules_condition_info() {
	return array(
		'clade_subscriptions_node_is_clade_content_type' => array(
			'label' => t('Node is a Clade content type'),
			'arguments' => array(
				'node' => array('type' => 'node', 'label' => t('The node being posted')),
			),
			'module' => 'Clade',
		),
	);
}

function clade_subscriptions_rules_action_info() {
	return array(
		'clade_subscriptions_send_new_content_notification' => array(
			'label' => t('Notify Clade members of new content'),
			'arguments' => array(
				'node' => array('type' => 'node', 'label' => t('The node being posted')),
			),
			'module' => 'Clade',
			'eval input' => array('subject', 'message', 'from'),
		),
		'clade_subscriptions_send_update_notification' => array(
			'label' => t('Notify Clade members of updated content'),
			'arguments' => array(
				'node' => array('type' => 'node', 'label' => t('The node being updated')),
				'user' => array('type' => 'user', 'label' => t('The User making the update')),
			),
			'module' => 'Clade',
			'eval input' => array('subject', 'message', 'from'),
		),
		'clade_subscriptions_send_comment_notification' => array(
			'label' => t('Notify Clade members of new comments'),
			'arguments' => array(
				'node' => array('type' => 'node', 'label' => t('The node being commented on')),
				'comment' => array('type' => 'comment', 'label' => t('The new comment')),
			),
			'module' => 'Clade',
			'eval input' => array('subject', 'message', 'from'),
		),
	);
}

function clade_subscriptions_node_is_clade_content_type($node) {
	$type = $node->type;
	$node_types = module_invoke_all('clade', 'clade node types');
	foreach ($node_types as $node_type) {
		if ($node_type === $type) {
			return TRUE;
		}
	}
	return FALSE;
}

function clade_subscriptions_send_new_content_notification($node, $settings) {
	// get members
	$clade = clade_determine_context_for_node($node);
	$members = clade_subscriptions_clade_members($clade);
	foreach ($members as $member) {
		$subPrefs = clade_subscriptions_get_subscriptions_preferences($member, $clade->tid);
		if ($subPrefs[$node->type]['new'] && $member != $node->uid) {
			$account = user_load($member);
			$to = 'mrhanlon@tacc.utexas.edu';//$account->mail;
			$from = ($settings['from']) ? str_replace(array("\r", "\n"), '', $settings['from']) : NULL;
			$message = drupal_mail('clade_subscriptions', 'clade_subscriptions_send_new_content_notification', $to, user_preferred_language($account), $settings, $from);
			if ($message['result']) {
				watchdog('clade_subscriptions', 'Successfully sent update notification to %recipient', array('%recipient' => $to));
			}
		}
	}
}

function clade_subscriptions_send_update_notification($node, $user, $settings) {
	// get members
	$clade = clade_determine_context_for_node($node);
	$members = clade_subscriptions_clade_members($clade);
	foreach ($members as $member) {
		$subPrefs = clade_subscriptions_get_subscriptions_preferences($member, $clade->tid);
		if ($subPrefs[$node->type]['update'] && $member != $user->uid) {
			$account = user_load($member);
			$to = 'mrhanlon@tacc.utexas.edu';//$account->mail;
			$from = ($settings['from']) ? str_replace(array("\r", "\n"), '', $settings['from']) : NULL;
			$message = drupal_mail('clade_subscriptions', 'clade_subscriptions_send_update_notification', $to, user_preferred_language($account), $settings, $from);
			if ($message['result']) {
				watchdog('clade_subscriptions', 'Successfully sent update notification to %recipient', array('%recipient' => $to));
			}
		}
	}
}

function clade_subscriptions_send_comment_notification($node, $comment, $settings) {
	// get members
	$clade = clade_determine_context_for_node($node);
	$members = clade_subscriptions_clade_members($clade);
	foreach ($members as $member) {
		$subPrefs = clade_subscriptions_get_subscriptions_preferences($member, $clade->tid);
		if ($subPrefs[$node->type]['comment'] && $member != $comment->uid) {
			$account = user_load($member);
			$to = 'mrhanlon@tacc.utexas.edu';//$account->mail;
			$from = ($settings['from']) ? str_replace(array("\r", "\n"), '', $settings['from']) : NULL;
			$message = drupal_mail('clade_subscriptions', 'clade_subscriptions_send_comment_notification', $to, user_preferred_language($account), $settings, $from);
			if ($message['result']) {
				watchdog('clade_subscriptions', 'Successfully sent update notification to %recipient', array('%recipient' => $to));
			}
		}
	}
}
