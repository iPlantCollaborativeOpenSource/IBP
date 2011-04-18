<?php
/**
 */
class clade_handler_field_clade_post_count_new extends views_handler_field_numeric {
  function query() {
    global $user;
		$table = $this->query->ensure_table('term_data');
    $sql = "SELECT COUNT(*) FROM {term_data} td INNER JOIN {term_node} tn ON tn.tid = td.tid INNER JOIN {node} n ON n.nid = tn.nid LEFT JOIN {history} h ON n.nid = h.nid AND h.uid = %uid WHERE n.status = 1 AND td.tid = $table.tid AND h.timestamp IS NULL AND n.created > %created";
    $sql = strtr($sql, array('%uid' => $user->uid, '%created' => NODE_NEW_LIMIT));
    $this->query->add_field('', "($sql)", 'post_count_new');
    $this->field_alias = 'post_count_new';
  }
  
  function render($values) {
    if ($cnt = $values->{$this->field_alias}) {
      return theme('mark', MARK_NEW);
    }
  }
}