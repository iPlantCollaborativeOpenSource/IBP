<?php
/**
 * Field handler to approve/deny a subscription request, or remove a member.
 *
 * @ingroup views_field_handlers
 */
class clade_subscriptions_handler_field_clade_uid_managelinkadmin extends clade_subscriptions_handler_field_clade_uid {
  function construct() {
    parent::construct();
    $this->additional_fields['tid'] = array('table' => 'clade_uid', 'field' => 'tid');
		$this->additional_fields['is_admin'] = array('table' => 'clade_uid', 'field' => 'is_admin');
  }

  function render($values) {
    if (isset($values->{$this->field_alias})) {
      $uid = $values->{$this->field_alias};
      $tid = $values->{$this->aliases['tid']};
      $is_admin = $values->{$this->aliases['is_admin']};
      $clade = clade_get_clade($tid);
      $admins = clade_subscriptions_clade_admins($clade);
      // Only show links to clade admins.  Show admin status next to admins
      if (! in_array($uid, $admins)) {
				$item = menu_get_item("clade/$tid/members/create_admin/$uid");
				if ($item['access']) {
					return l(t('Make manager'), "clade/$tid/members/create_admin/$uid", array('query' => drupal_get_destination()));
				}
      } else {
      	$output = t('Yes');
      	if (count($admins) > 1) {
      		// if multiple managers, allow site admins to demote manager
					$item = menu_get_item("clade/$tid/members/remove_admin/$uid");
					if ($item['access']) {
						$output .= ' (' . l(t('Remove manager'), "clade/$tid/members/remove_admin/$uid", array('query' => drupal_get_destination())) . ')';
					}
      	}
      	return $output;
      }
    }
  }
}
