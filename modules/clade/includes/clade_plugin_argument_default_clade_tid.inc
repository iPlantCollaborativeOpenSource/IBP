<?php
// $Id$
/**
 * @file
 * Contains the clade argument default plugin.
 */

/**
 * Default argument plugin to extract the current clade.
 */
class clade_plugin_argument_default_clade_tid extends views_plugin_argument_default {
  function argument_form(&$form, &$form_state) {
  }

  function get_argument() {
    if ($clade = clade_get_context()) {
      return $clade->tid;
    }
  }
}
