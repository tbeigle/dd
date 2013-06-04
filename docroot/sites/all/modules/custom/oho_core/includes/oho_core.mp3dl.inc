<?php

/**
 * Callback for the mp3 download
 */
function oho_mp3_download($nid = 0, $field_name = '') {
  $missing = '<p>'.t('Sorry. The file you are trying to download is missing.').'</p>';
  
  if (!empty($nid) && !empty($field_name)) {
    $node = node_load($nid);
    
    $field = field_get_items('node', $node, $field_name);
    $field_value = field_view_value('node', $node, $field_name, $field[0]);
    
    $uri = !empty($field_value['#file']->uri) ? $field_value['#file']->uri : '';
    $fid = !empty($field_value['#file']->fid) ? $field_value['#file']->fid : 0;
    
    $file = '';
    
    if (!empty($uri)) {
      $file = drupal_realpath($uri);
      $file_name = drupal_basename($uri);
    }
  }
  
  if (!empty($file) && !empty($file_name)) {
    drupal_add_http_header('Content-Type', 'octet/stream');
    drupal_add_http_header('Content-disposition', 'attachment; filename='.$file_name.';"');
    drupal_add_http_header('Content-Length', filesize($file));
    readfile($file);
  } else {
    return '<p>'.t('Sorry. The file you are trying to download is missing.').'</p>';
  }
}

/**
 * Title callback for mp3 downloads
 */
function oho_mp3_title_response($nid = 0, $field_name = '') {
  if (!empty($nid) && !empty($field_name)) {
    $node = node_load($nid);
    
    if (!empty($node->title)) {
      $title = $node->title;
    } else {
      $field = field_get_items('node', $node, $field_name);
      $field_value = field_view_value('node', $node, $field_name, $field[0]);
      
      $uri = !empty($field_value['#file']->uri) ? $field_value['#file']->uri : '';
      $fid = !empty($field_value['#file']->fid) ? $field_value['#file']->fid : 0;
      
      if (!empty($uri)) {
        $title = drupal_basename($uri);
      }
    }
  }
  
  if (!empty($title)) {
    return $title;
  } else {
    return 'File Not Found';
  }
}