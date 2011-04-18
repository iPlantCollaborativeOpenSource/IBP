<?php

/**
 * Base class for most {clade_uid} field handlers.
 */
class clade_subscriptions_handler_field_clade_uid extends views_handler_field {
  function query() {
    if ($this->view->base_table !== 'users' || ($clade = clade_get_context())) {
      parent::query();
    }
  }
}
