<?php

/**
 * Condition: Check for terms; Configuration form.
 */
function ibphelper_condition_content_has_term_form($settings, &$form) {
  $vocabularies = taxonomy_get_vocabularies();
  $options = array();
  foreach ($vocabularies as $vocabulary) {
    $terms = taxonomy_get_tree($vocabulary->vid);
    foreach($terms as $term) {
      $options[check_plain($vocabulary->name)][$term->tid] = check_plain($term->name);
    }
  }
  $form['settings']['tids'] = array(
    '#type' => 'select',
    '#title' => t('Taxonomy terms'),
    '#options' => $options,
    '#multiple' => TRUE,
    '#size' => min(20, count($options, 1)),
    '#default_value' => isset($settings['tids']) ? $settings['tids'] : array(),
    '#required' => TRUE,
  );
}