<?php

function clade_subscriptions_send_new_content_notification_form($settings, &$form) {
	rules_action_mail_to_user_form($settings, $form);
}

function clade_subscriptions_send_update_notification_form($settings, &$form) {
	rules_action_mail_to_user_form($settings, $form);
}

function clade_subscriptions_send_comment_notification_form($settings, &$form) {
	rules_action_mail_to_user_form($settings, $form);
}