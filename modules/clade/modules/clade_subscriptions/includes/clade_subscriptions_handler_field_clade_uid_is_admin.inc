<?php
/**
 * Field handler to show if user is admin or not.
 *
 * @ingroup views_field_handlers
 */
class clade_subscriptions_handler_field_clade_uid_is_admin extends clade_subscriptions_handler_field_clade_uid {
  function render($values) {
    if (isset($values->{$this->field_alias})) {
      $is_admin = $values->{$this->field_alias};
      if ($is_admin) {
        return t('admin');
      }
    }
  }
}
