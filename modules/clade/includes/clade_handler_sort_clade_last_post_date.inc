<?php
/**
 */
class clade_handler_sort_clade_last_post_date extends views_handler_sort {
  function query() {
		$table = $this->query->ensure_table('term_data');
    $sql = "SELECT MAX(GREATEST(n.changed, stat.last_comment_timestamp)) FROM {term_node} tn INNER JOIN {node} n ON n.nid = tn.nid INNER JOIN {node_comment_statistics} stat ON n.nid = stat.nid WHERE n.status = 1 AND tn.tid = $table.tid";
    $this->query->add_field('', "($sql)", 'last_post_date');
    $this->field_alias = 'last_post_date';

  	$this->query->add_orderby(NULL, NULL, $this->options['order'], 'last_post_date');
  }

}