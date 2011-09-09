<?php
// $Id$

// Declare all the .view files in the views subdir that end in .view
function ibp_projects_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'ibp_projects'). '/views', '.view');
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[$file->name] = $view;
    }
  }
  return $views;
}

