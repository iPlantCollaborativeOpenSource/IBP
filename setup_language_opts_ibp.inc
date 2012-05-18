<?php
db_query("UPDATE {node} SET language = 'en' WHERE language = ''");
$types = node_get_types();
foreach ($types as $name => $type) {
	echo "Configuring langauge settings for ".$name."...\n";
	variable_set("language_content_type_".$name, 2)."\n";
	variable_set("i18n_node_".$name, "1")."\n";
	variable_set("i18n_newnode_current_".$name, 1)."\n";
	variable_set("i18n_required_node_".$name, 1)."\n";
}
?>
