<?php
class clade_handler_argument_clade_tid extends views_handler_argument_numeric {
  // Set context based on first node passed.
  function query() {
    $args = explode(',', $this->argument);
    $clade = clade_get_clade((int)$args[0]);
    clade_set_context($clade);
    parent::query();
  }
  
  /**
   * Override the behavior of title(). Get the title of the node.
   */
  function title_query() {
    $titles = array();
    $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));
    $result = db_query("SELECT t.name FROM {term_data} t WHERE t.tid IN ($placeholders)", $this->value);
    while ($term = db_fetch_object($result)) {
      $titles[] = check_plain($term->name);
    }

    return $titles;
  }
}
