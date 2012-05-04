<?php

/**
 * Implementation of hook_rules_condition_info().
 */
function ibphelper_rules_condition_info() {
  return array(
    'ibphelper_condition_content_has_term' => array(
      'label' => t('Content has term'),
      'help' => t('Evaluates to TRUE if the given content has one of the selected terms.'),
      'module' => 'IBP Helper',
      'arguments' => array(
        'node' => array('type' => 'node', 'label' => t('Content')),
      ),
    ),
  );
}

/**
 * Condition: Check for selected terms.
 */
function ibphelper_condition_content_has_term(&$node, $settings) {

  $taxonomy = $node->taxonomy;

  // If vocab is marked as tag, we format it to the proper format.
  if (isset($taxonomy['tags']) && count($taxonomy['tags']) > 0) {
    foreach ($taxonomy['tags'] as $vid => $term) {
      $terms_names = explode(', ', $term);
      foreach ($terms_names as $term_name) {
        // It can return multiple terms with the same name.
        $terms_objects = taxonomy_get_term_by_name($term_name);
        foreach ($terms_objects as $term_object) {
          $tid = $term_object->tid;
          // Avoid terms with same name in different vocabularies.
          if ($term_object->vid == $vid){
            $taxonomy[$vid][$tid] = $tid;
          }
        }
      }
    }
    // Since we won't use it unset to not bother us.
    unset($taxonomy['tags']);
  }


  if (isset($taxonomy) && (count($taxonomy) > 0)) {
    $tids = array();

    foreach ($taxonomy as $vocab) {
      if (!empty($vocab) && is_array($vocab)) {
        foreach ($vocab as $term) {
          $tid = is_object($term) ? $term->tid : (is_array($term) ? reset($term) : $term);
          $tids[$tid] = $tid;
        }
      }
      else {
        if (!empty($vocab) && is_numeric($vocab)) {
          $tids[$vocab] = $vocab;
        }
      }
    }

    foreach ($settings['tids'] as $tid) {
      if (isset($tids[$tid])) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

