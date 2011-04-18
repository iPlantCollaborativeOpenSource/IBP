<?php
/**
 * Field handler to approve/deny a subscription request, or remove a member.
 *
 * @ingroup views_field_handlers
 */
class clade_subscriptions_handler_field_clade_uid_managelink extends clade_subscriptions_handler_field_clade_uid {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = array('table' => 'clade_uid', 'field' => 'tid');
  }

  function render($values) {
    if (isset($values->{$this->field_alias})) {
      $uid = $values->{$this->field_alias};
      $tid = $values->{$this->aliases['tid']};
      $clade = clade_get_clade($tid);
      $admins = clade_subscriptions_clade_admins($clade);
      // Only show links to group admins. And don't show next to group manager.
      if (! in_array($uid, $admins)) {
				$item = menu_get_item("clade/$tid/members/unjoin/$uid");
				if ($item['access']) {
					return l(t('Remove membership'), "clade/$tid/members/unjoin/$uid", array('query' => drupal_get_destination()));
				}
      }
    }
  }
}
