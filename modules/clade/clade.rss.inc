<?php
function clade_rss($clade) {
	$channel = array(
		'link' => url(taxonomy_term_path($clade), array(absolute => 'TRUE')),
		'title' => $clade->name,
		'description' => $clade->description,
		);
	
	$sql = "SELECT distinct n.nid, greatest(n.created, ncs.last_comment_timestamp) as modified " .
				 "FROM {node} n " .
				 "JOIN {node_comment_statistics} ncs ON n.nid = ncs.nid " .
				 "JOIN {term_node} tn ON tn.nid = n.nid " .
				 "JOIN {term_data} td ON td.tid = tn.tid " .
				 "WHERE " .
				 "td.tid = %d " .
				 "AND td.vid = %d " .
				 "ORDER BY " .
				 "modified desc ";
	$args = array();
	$args[] = $clade->tid;
	$args[] = variable_get('clade_vocabulary', 0);

	$results = db_query($sql, $args);
	$items = array();
	while ($row = db_fetch_object($results)) {
		$items[] = $row->nid;
	}
	return node_feed($items, $channel);
}