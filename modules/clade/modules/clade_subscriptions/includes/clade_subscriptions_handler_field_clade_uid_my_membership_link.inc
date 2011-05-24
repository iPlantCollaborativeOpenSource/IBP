<?php
/**
 */
class clade_subscriptions_handler_field_clade_uid_my_membership_link extends clade_subscriptions_handler_field_clade_uid {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = array('table' => 'clade_uid', 'field' => 'tid');
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['show_join'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['show_join'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show join links if not a member'),
      '#default_value' => $this->options['show_join'],
    );
  }
  
  function render($values) {
    if (isset($values->{$this->field_alias})) {
      $tid = $values->{$this->aliases['tid']};
      global $user;
      if ($user->uid) {
				if (in_array($tid, array_keys($user->clades))) {
					return l(t('My membership'), "clade/$tid/my-membership");
				} else if ($this->options['show_join']) {
					return l(t('Join'), "clade/$tid/members/join");
				}
			}
    }
  }
}
