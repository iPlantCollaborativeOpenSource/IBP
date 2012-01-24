<?php

function biblio_helper_drush_command() {
	$items = array();
	
	$items['biblio-helper-reset-fields'] = array(
		'callback' => 'biblio_helper_configure_biblio_types',
		'description' => 'Reset biblio stuff how IBP needs it',
		'aliases' => array('bibhelper-reset'),
	);
	
	return $items;
}

function biblio_helper_configure_biblio_types() {

	// reset biblio to defaults
  module_load_include('install', 'biblio');
  biblio_reset_types();

	// common
	$visible = array('biblio_authors', 'biblio_year', 'biblio_keywords', 'biblio_url', 'biblio_doi');
	$vfids = array();
	foreach ($visible as $field_name) {
		$vfids[] = _biblio_helper_map_biblio_field($field_name);
	}
	db_query("UPDATE {biblio_field_type} SET common = 0 WHERE fid NOT IN (%d,%d,%d,%d,%d)", $vfids);
	
	$required = array('biblio_authors', 'biblio_year');
	$rfids = array();
	foreach ($required as $field_name) {
		$rfids[] = _biblio_helper_map_biblio_field($field_name);
	}
	db_query("UPDATE {biblio_field_type} SET required = 0 WHERE fid NOT IN (%d,%d)", $rfids);
	
	$pub_types = array(
		100 => array( // book
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_authors',
				'biblio_accession_number',
				'biblio_isbn',
				'biblio_call_number',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_edition',
				'biblio_volume',
				'biblio_pages',
				'biblio_keywords',
				'biblio_url',
				'biblio_number_of_volumes',
				'biblio_original_publication',
				'biblio_reprint_edition',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		101 => array( // book chapter
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_authors',
				'biblio_accession_number',
				'biblio_isbn',
				'biblio_call_number',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_edition',
				'biblio_volume',
				'biblio_number',
				'biblio_secondary_title',
				'biblio_pages',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_number_of_volumes',
				'biblio_original_publication',
				'biblio_reprint_edition',
				'biblio_section',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		102 => array( // journal article
			'visible' => array(
				'biblio_authors',
				'biblio_accession_number',
				'biblio_isbn',
				'biblio_call_number',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_edition',
				'biblio_volume',
				'biblio_number',
				'biblio_secondary_title',
				'biblio_pages',
				'biblio_date',
				'biblio_abst_e',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_number_of_volumes',
				'biblio_original_publication',
				'biblio_reprint_edition',
				'biblio_issn',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		103 => array( // conference paper
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_title',
				'biblio_accession_number',
				'biblio_isbn',
				'biblio_call_number',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_edition',
				'biblio_volume',
				'biblio_number',
				'biblio_pages',
				'biblio_date',
				'biblio_abst_e',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_number_of_volumes',
				'biblio_original_publication',
				'biblio_reprint_edition',
				'biblio_section',
				'biblio_issn',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		104 => array( // conference proceedings
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_title',
				'biblio_accession_number',
				'biblio_isbn',
				'biblio_call_number',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_edition',
				'biblio_volume',
				'biblio_number',
				'biblio_pages',
				'biblio_date',
				'biblio_abst_e',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_number_of_volumes',
				'biblio_original_publication',
				'biblio_reprint_edition',
				'biblio_section',
				'biblio_issn',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		105 => array( // newspaper articles
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_title',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_date',
				'biblio_volume',
				'biblio_number',
				'biblio_pages',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_section',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		106 => array( // magazine article
			'visible' => array(
				'biblio_authors',
				'biblio_secondary_title',
				'biblio_isbn',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_year',
				'biblio_date',
				'biblio_abst_e',
				'biblio_volume',
				'biblio_pages',
				'biblio_keywords',
				'biblio_url',
				'biblio_issue',
				'biblio_issn',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
		107 => array( // web article
			'visible' => array(
				'biblio_authors',
				'biblio_publisher',
				'biblio_place_published',
				'biblio_number',
				'biblio_year',
				'biblio_date',
				'biblio_keywords',
				'biblio_url',
				'biblio_doi'
			),
			'required' => array('biblio_authors', 'biblio_year'),
		),
	);
	
	foreach ($pub_types AS $tid => $settings) {
		$visible = $settings['visible'];
		$vfids = array();
		foreach ($visible as $field_name) {
			$vfids[] = _biblio_helper_map_biblio_field($field_name);
		}
		
		$required = $settings['required'];
		$rfids = array();
		foreach ($required as $field_name) {
			$rfids[] = _biblio_helper_map_biblio_field($field_name);
		}
		
		$placeholders = array();
		for ($i = 0; $i < count($vfids); $i++) {
			$placeholders[] = "%d";
		}
		
		$sql = "UPDATE {biblio_field_type} SET visible = 0 WHERE tid = %d and fid NOT IN (" . implode(",", $placeholders) . ")";
		db_query($sql, array_merge(array($tid), $vfids));
		
		$sql = "UPDATE {biblio_field_type} SET visible = 1 WHERE tid = %d and fid IN (" . implode(",", $placeholders) . ")";
		db_query($sql, array_merge(array($tid), $vfids));
		
		$placeholders = array();
		for ($i = 0; $i < count($rfids); $i++) {
			$placeholders[] = "%d";
		}
		
		$sql = "UPDATE {biblio_field_type} SET required = 0 WHERE tid = %d AND fid NOT IN (" . implode(",", $placeholders) . ")";
		db_query($sql, array_merge(array($tid), $rfids));
		
		$sql = "UPDATE {biblio_field_type} SET required = 1 WHERE tid = %d AND fid IN (" . implode(",", $placeholders) . ")";
		db_query($sql, array_merge(array($tid), $rfids));
	}
	
	$weights = array(
		array(1,1), array(2,2), array(15,3), array(13,4), array(14,5),
		array(16,6), array(17,7), array(37,8), array(6,9), array(18,10),
		array(28,11), array(43,12), array(19,13), array(20,14), array(25,15),
		array(46,16), array(9,17), array(8,18), array(10,19), array(11,20),
		array(24,22), array(26,22), array(47,23), array(41,24), array(42,25),
		array(22,26), array(3,27), array(4,28), array(5,29), array(7,30),
		array(21,31), array(12,32), array(23,33), array(27,34), array(29,35),
		array(30,36), array(31,37), array(32,38), array(33,39), array(34,40),
		array(35,41), array(36,42), array(38,43), array(39,44), array(40,45),
		array(44,46), array(45,47), array(49,48), array(50,49), array(48,50),
		array(51,51), array(52,52), array(53,53)
	);
	$sql = "UPDATE {biblio_field_type} SET weight = %d WHERE fid = %d";
	foreach ($weights as $w) {
		db_query($sql, array_reverse($w));
	}
	
	/**
	 * field data
	 * array(
	 *   tid => array(
	 *     field_name => title
	 *   )
	 * )
	 */
	$data = array(
		100 => array(
			'biblio_secondary_authors' => 'Editor',
			'biblio_issn' => 'ISSN Number'
		),
		101 => array(
			'biblio_issn' => 'ISSN Number'
		),
		102 => array(
			'biblio_issn' => 'ISSN Number'
		),
		104 => array(
			'biblio_issn' => 'ISSN Number'
		),
		105 => array(	
			'biblio_issn' => 'ISSN Number'
		),
		106 => array(
			'biblio_issn' => 'ISSN Number'
		),
		107 => array(
			'biblio_publisher' => 'Website Name',
			'biblio_place_published' => 'Website URL',
		),
	);
}

function _biblio_helper_map_biblio_field($field) {
	static $typemap = array(
		'biblio_authors' => 1,
		'biblio_secondary_authors' => 2,
		'biblio_year' => 15,
		'biblio_publisher' => 13,
		'biblio_place_published' => 14,
		'biblio_edition' => 16,
		'biblio_volume' => 17,
		'biblio_number_of_volumes' => 37,
		'biblio_secondary_title' => 6,
		'biblio_number' => 18,
		'biblio_issue' => 28,
		'biblio_section' => 43,
		'biblio_pages' => 19,
		'biblio_date' => 20,
		'biblio_type_of_work' => 25,
		'biblio_issn' => 46,
		'biblio_isbn' => 9,
		'biblio_accession_number' => 8,
		'biblio_call_number' => 10,
		'biblio_other_number' => 11,
		'biblio_keywords' => 24,
		'biblio_url' => 26,
		'biblio_doi' => 47,
		'biblio_original_publication' => 41,
		'biblio_reprint_edition' => 42,
		'biblio_abst_e' => 22,
		'biblio_tertiary_authors' => 3,
		'biblio_subsidiary_authors' => 4,
		'biblio_corp_authors' => 5,
		'biblio_tertiary_title' => 7,
		'biblio_lang' => 21,
		'biblio_other_author_affiliations' => 12,
		'biblio_abst_f' => 23,
		'biblio_notes' => 27,
		'biblio_research_notes' => 29,
		'biblio_custom1' => 30,
		'biblio_custom2' => 31,
		'biblio_custom3' => 32,
		'biblio_custom4' => 33,
		'biblio_custom5' => 34,
		'biblio_custom6' => 35,
		'biblio_custom7' => 36,
		'biblio_short_title' => 38,
		'biblio_alternate_title' => 39,
		'biblio_translated_title' => 40,
		'biblio_citekey' => 44,
		'biblio_coins' => 45,
		'biblio_remote_db_name' => 49,
		'biblio_remote_db_provider' => 50,
		'biblio_auth_address' => 48,
		'biblio_label' => 51,
		'biblio_access_date' => 52,
		'biblio_refereed' => 53,
	);
	
	return $typemap[$field];
}