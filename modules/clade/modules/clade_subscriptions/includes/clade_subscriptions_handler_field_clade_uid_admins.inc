<?php
/**
 * Field handler to show clade admins.
 *
 * @ingroup views_field_handlers
 */
class clade_subscriptions_handler_field_clade_uid_admins extends clade_subscriptions_handler_field_clade_uid {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = array('table' => 'clade_uid', 'field' => 'tid');
  }

  function render($values) {
    if (isset($values->{$this->field_alias})) {
      $tid = $values->{$this->aliases['tid']};
      $clade = clade_get_clade($tid);
      $admins = clade_subscriptions_clade_admins($clade);
      $output = array();
      foreach ($admins as $admin) {
      	$output[] = theme('username', user_load($admin));
      }
      return implode(', ', $output);
    }
  }
}
