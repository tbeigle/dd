<?php

/**
 * @file
 *   OHO dev Drush commands for working with development sites
 */

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function oho_core_drush_command() {
  $items = array();
    
  $items['oho-domain-fix'] = array(
    'description' => "Updates the domain table after a sql-sync overwrites its records.",
    'arguments' => array(
      'domain' => 'The primary domain name for which you wish to update the domain table records.',
    ),
    'options' => array(
      'did' => 'Enter an optional comma-separated list of domain_id values if you only want to update specific records tied to those values.',
    ),
    'examples' => array(
      'drush oho-domain-fix dev.mydomain.com --did=1,2' => 'Update subdomain fields for domains 1 and 2 to use dev.domain.com as the primary domain.',
      'drush oho-df dev.mydomain.com --did=1,2' => 'Same as the previous example but using the command alias.',
    ),
    'core' => array(7),
    'drupal dependencies' => array(
      'domain',
    ),
    'aliases' => array('oho-df'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  
  $items['oho-disable-theme-blocks'] = array(
    'description' => "Moves all blocks to the disabled region for a specified theme.",
    'arguments' => array(
      'theme' => 'The machine name of the theme for which you wish to disable all blocks.',
    ),
    'examples' => array(
      'drush oho-disable-theme-blocks sometheme' => 'Disable all blocks for the sometheme theme.',
      'drush oho-dtb sometheme' => 'Same as the previous example but using the command alias.',
    ),
    'core' => array(6,7),
    'aliases' => array('oho-dtb'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  
  $items['oho-demote-nodes'] = array(
    'description' => "Removes 'featured' nodes from the front page.",
    'examples' => array(
      'oho-demote-nodes' => 'Un-features all nodes',
      'oho-dn' => 'Same thing but using the command alias',
    ),
    'core' => array(7),
    'aliases' => array('oho-dn'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  
  $items['oho-taxonomy-access-control-options-fix'] = array(
    'description' => 'This corrects issues arising from the uninstallation of the taxonomy access control module.',
    'examples' => array(
      'drush oho-taxonomy-access-options-fix' => 'Unsets the setting using the nonexistent _taxonomy_access_term_options function call.',
    ),
    'core' => array(7),
    'aliases' => array('oho-tac-of'),
    'bootstrap' => DRUSH_BOOTSTRAP_FULL,
  );
  
  $items['oho-taxonomy-add-terms'] = array(
    'description' => 'Add multiple taxonomy terms to one or more vocabularies at once.',
    'arguments' => array(
      'vid' => 'The vid for the default vocabulary to which the terms should be assigned. You may override this on a per-term basis.',
      'terms' => 'A list of space-delimited terms to add. Enclose each term in single or double quotes. For each term you must include the name and you may include a vid (if different from the value for the vid argument), a description, a text-editor format, and/or a weight. Term settings should be separated by two pipe symbols ("||"). If a machine_name for a format is not specified then plain_text will be used as a default.',
    ),
    'examples' => array(
      'drush oho-taxonomy-add-terms 2 "Term 1 Name" "Term 2 Name"' => 'Uses the full command name rather than the alias to add two terms to the vocabulary with vid 2 setting only the name values for each term.',
      'drush oho-tat 2 "Term 1 Name||vid==1||description==<p>Term description goes here.</p>||format==full_html||weight==-1"' => 'Add a term to the vocabulary setting its vid to 1 (overriding the vid default of 2), description to a simple HTML paragraph, format to full_html, and weight to  -1.',
    ),
    'core' => array(7),
    'aliases' => array('oho-tat'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  
  $items['oho-taxonomy-show-terms'] = array(
    'description' => "Prints out taxonomy term names.",
    'options' => array(
      'vocabularies' => 'Comma-separated list of vid values for vocabularies from which terms should be selected.',
      'sort' => 'Criteria to use for query sort ordering.',
      'limit' => 'A maximum number of query results to return and/or a limit offset.',
    ),
    'examples' => array(
      'drush oho-show-taxonomy-terms' => 'Uses the full command name rather than the alias to print all taxonomy term names.',
      'drush oho-tst --sort=name/asc,vid/desc,tid,weight' => 'Prints term names ordered by the specified criteria.',
      'drush oho-tst --vocabularies=1,3' => 'Prints term names from the two specified vocabularies.'."\n".
                                            'Note: You can run "drush oho-stv" to find available vocabulary vid values.',
      'drush oho-tst --limit=5' => 'Prints term names for the first five term results.',
      'drush oho-tst --limit=5,2' => 'Prints the term names for term results 3, 4, 5, 6, and 7.',
    ),
    'core' => array(7),
    'drupal dependencies' => array(
      'taxonomy',
    ),
    'aliases' => array('oho-tst'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
    
  $items['oho-taxonomy-show-vocabularies'] = array(
    'description' => "Prints out a list of all taxonomy vocabularies.",
    'examples' => array(
      'drush oho-taxonomy-show-vocabularies' => 'Show the name, machine_name, and vid values for all taxonomy vocabularies.',
      'drush oho-tsv' => 'Same as the previous example but using the command alias.',
    ),
    'core' => array(7),
    'drupal dependencies' => array(
      'taxonomy',
    ),
    'aliases' => array('oho-tsv'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function oho_core_drush_help($section) {
  switch ($section) {
    case 'drush:oho-demote-nodes': {
      return dt('This command will remove all featured nodes from the front page.');
      break;
    }
    case 'drush:oho-disable-theme-blocks': {
      return dt("This command will disable all blocks for a specified theme.");
      break;
    }
    case 'drush:oho-domain-fix': {
      return dt("This command will update a site's domain table with your domain records if the data therein was previously overwritten.");
      break;
    }
    case 'drush:oho-taxonomy-add-terms': {
      return dt('Use this command to add multiple taxonomy terms to one or more vocabularies at once.');
      break;
    }
    case 'drush:oho-taxonomy-show-terms': {
      return dt("This command will print the names for all or some of the site's taxonomy terms.");
      break;
    }
    case 'drush:oho-taxonomy-show-vocabularies': {
      return dt('This command will print out data for all taxonomy vocabularies in alphabetical order.');
      break;
    }
  }
}

/***************************
COMMAND VALIDATIONS
***************************/

/*
 * Implementation of drush_hook_COMMAND_validate()
 *
 * Validates the oho-domain-fix command
 */
function drush_oho_core_oho_domain_fix_validate($domain = NULL) {
  if (!isset($domain)) {
    return drush_set_error('OHO_CORE_DOMAIN_FIX_PROBLEM', dt('You must enter a domain name to run this command.'));
  }
}

/*
 * Implementation of drush_hook_COMMAND_validate()
 *
 * Validates the oho-disable-theme-blocks command
 */
function drush_oho_core_oho_disable_theme_blocks_validate($theme = NULL) {
  if (!isset($theme)) {
    return drush_set_error('OHO_CORE_DISABLE_THEME_BLOCKS_PROBLEM', dt('You must enter a theme to run this command.'));
  }
}

/**
 * Implementation of drush_hook_COMMAND_validate()
 *
 * Validates the oho-taxonomy-add-terms command
 */
function drush_oho_core_oho_taxonomy_add_terms_validate() {
  $args = func_get_args();
  $has_args = TRUE;
  
  if (empty($args[1])) {
    $error = dt('Both the vid and at least one term argument are required.');
    return drush_set_error('OHO_CORE_TAXONOMY_ADD_TERMS_PROBLEM', $error);
  }
  
  if (!is_numeric($args[0])) {
    $error = dt('You must enter a numeric VID for the vocabulary to which you wish to add terms.');
    return drush_set_error('OHO_CORE_TAXONOMY_ADD_TERMS_PROBLEM', $error);
  }
}

/***************************
COMMAND CALLBACKS
***************************/

/**
 * Drush command callback for the OHO taxonomy access control options fix
 */
function drush_oho_core_oho_taxonomy_access_control_options_fix() {
  $fields = field_read_fields();
  foreach ($fields as $field_name => $field) {
    if ($field['type'] == 'taxonomy_term_reference') {
      if ($field['settings']['options_list_callback'] == '_taxonomy_access_term_options') {
        $field['settings']['options_list_callback'] = '';
        field_update_field($field);
        drush_print("\n".'Updated '.$field['field_name'].'.');
      }
    }
  }
}

/**
 * Drush command callback for the OHO denote nodes command
 *
 * Updates records in the node table, removing them from the
 * site front page.
 */
function drush_oho_core_oho_demote_nodes() {
  $count = db_query('SELECT COUNT(*) FROM {node} WHERE `promote` = :promote', array(':promote' => 1))->fetchField();
  
  if (empty($count)) {
    drush_print("\n".dt('There are currently no nodes featured on the front page.')."\n");
  } elseif (drush_confirm(dt('Do you really want to remove all !count "featured" nodes from the front page?', array('!count' => $count)))) {
    $updated = db_update('node')
    ->fields(array('promote' => 0))
    ->condition('promote', 1, '=')
    ->execute();
    
    drush_print("\n".dt('Demoted !count nodes so that none are featured on the front page.', array('!count' => $count))."\n");
  }
}

/**
 * Drush command callback for the OHO disable theme blocks command
 *
 * Updates records in the blocks table, clearing the values in their
 * `region` fields wherever their `theme` field values match the
 * theme name argument.
 *
 * @param
 *   - $theme: the name of the theme for which all blocks should be disabled
 *
 */
function drush_oho_core_oho_disable_theme_blocks($theme = '') {
  $v = _oho_core_check_drupal_core();
  
  if ($v != 6 && $v != 7) {
    drush_print("\n".dt('Whoops. I made a mistake when checking for the Drupal version. Sorry.')."\n");
    return;
  }
  
  $vars = array(
    'query_ph' => array(
      6 => '"%s"',
      7 => ':theme',
    ),
    'query_val' => array(
      6 => $theme,
      7 => array(':theme' => $theme),
    ),
    'block_tbl' => array(
      6 => 'blocks',
      7 => 'block',
    ),
  );
  //SELECT COUNT(*) FROM `block` WHERE `theme` = 'rowan' AND `region` <> '-1';
  $sql =
    'SELECT `region` '.
    'FROM {'.$vars['block_tbl'][$v].'} '.
    'WHERE `theme` = '.$vars['query_ph'][$v].' '.
    'ORDER BY `theme`;';
  $results = db_query($sql, $vars['query_val'][$v]);
  $count = 0;
  
  if ($v == 6) {
    while ($row = db_result($results)) {
      if (!empty($row) && $row != '-1') {
        $count++;
      }
    }
  } elseif ($v == 7) {
    foreach ($results as $record) {
      if (!empty($record->region) && $record->region != '-1') {
        $count++;
      }
    }
  } else {
    drush_print("\n".dt('Whoops. I made a mistake when trying to count the blocks enabled for this theme. Sorry.')."\n");
    return;
  }
  
  if (empty($count)) {
    drush_print("\n".dt('There were no enabled blocks found for the !theme theme.', array('!theme' => $theme))."\n");
    return;
  }
  
  if (drush_confirm(dt('Do you really want to disable !count blocks for the !theme theme?', array('!count' => $count, '!theme' => $theme)))) {
    if ($v == 6) {
      $sql =
        'UPDATE {'.$vars['block_tbl'][$v].'} '.
        'SET `region` = "-1" '.
        'WHERE `theme` = '.$vars['query_ph'][$v].';';
      db_query($sql, $vars['query_val'][$v]);
    } elseif ($v == 7) {
      $updated = db_update($vars['block_tbl'][$v])
      ->fields(array(
        'region' => '-1',
      ))
      ->condition('theme', $theme, '=')
      ->execute();
    }
    
    drush_print("\n".dt('!count blocks were disabled for the !theme theme.', array('!count' => $count, '!theme' => $theme)));
  }
}

/**
 * Drush command callback for the OHO domain fix command
 *
 * Updates records in the domain table, matching subdomain field values
 * to a given domain name, and prints out details about the operations
 * performed.
 *
 * @param
 *   - $domain: the name of the domain to be used to update the domain table
 *
 */
function drush_oho_core_oho_domain_fix($domain = '') {  
  $did = FALSE;
  
  if ($did_option = drush_get_option('did')) {
    if (strpos($did_option, ',') === FALSE && !empty($did_option)) {
      $did = array($did_option);
    } elseif (!empty($did_option)) {
      $did = explode(',', $did_option);
      
      foreach ($did as $key => $d) {
        $d2 = trim($d);
        
        if (!is_numeric($d2)) {
          $did[$key] = $d2;
        } else {
          unset($did[$key]);
        }
      }
    }
  }
  
  if (function_exists('db_query') && function_exists('db_table_exists') && function_exists('db_field_exists')) {
    if (db_table_exists('domain') && db_field_exists('domain', 'subdomain')) {
      $sql =
        'SELECT * '.
        'FROM {domain} '.
        'ORDER BY `domain_id`;';
      $results = db_query($sql);
      
      $domains = array();
      $primary = NULL;
      
      while ($row = $results->fetchObject()) {
        if (!empty($row->is_default) && empty($primary)) {
          $primary = $row->subdomain;
        }
        
        if (!empty($primary) && (empty($did) || in_array($row->domain_id, $did))) {
          $domains[$row->domain_id] = array(
            'old' => $row->subdomain,
            'new' => str_replace($primary, $domain, $row->subdomain),
          );
        }
      }
      
      drush_print();
      
      if (drush_confirm(dt('Do you really want to change !primary to !domain?', array('!primary' => $primary, '!domain' => $domain)))) {
        $msg = "\n";
        $i = 0;
        
        foreach ($domains as $domain_id => $data) {
          $old = $data['old'];
          $new = $data['new'];
          
          $update = db_update('domain')
          ->fields(array(
            'subdomain' => $new,
          ))
          ->condition('domain_id', $domain_id, '=')
          ->execute();
          
          $msg .= dt('Updated domain !domain_id: Changed subdomain field from !old to !new', array(
            '!domain_id' => $domain_id,
            '!old' => $old,
            '!new' => $new
          ))."\n";
          
          $i++;
        }
        
        $msg .= "\n".dt('Updated subdomain fields in !count domain records.', array('!count' => $i))."\n";
        
        // Google CSE
        $google_cse = variable_get('google_cse_sitesearch', '');
        
        if (!empty($google_cse)) {
          $google_cse_up = str_replace($primary, $domain, $google_cse);
          variable_set('google_cse_sitesearch', $google_cse_up);
          $google_cse_new = variable_get('google_cse_sitesearch', '');
          
          $msg .= "\n".dt('Changed google_cse_sitesearch variable to !gcse', array('!gcse' => "\n".$google_cse_new))."\n";
        }
      }
    } else {
      $msg = dt('The domain table is missing.');
    }
  } else {
    $msg = dt('Sorry, bootstrap problem.');
  }
  
  drush_print($msg);
}

/**
 * Drush command callback for the OHO taxonomy add
 * terms command
 *
 * Add one or more terms to one or more vocabularies
 * with a single call to this function.
 */
function drush_oho_core_oho_taxonomy_add_terms() {
  $term_keys = array(
    'vid',
    'description',
    'format',
    'weight',
  );
  
  $args = func_get_args();
  $vid = array_shift($args);
  $vids = array();
  $insert_count = 0;
  
  // Build an array of vid values for available vocabularies
  $results = db_query('SELECT `vid` FROM {taxonomy_vocabulary};');
  
  foreach ($results as $row) {
    $vids[] = $row->vid;
  }
  
  // Build an array of format values for available filter formats
  $results = db_query('SELECT `format` FROM {filter_format};');
  
  foreach ($results as $row) {
    $formats[] = $row->format;
  }
  
  foreach($args as $arg) {
    $term = $term_arg = array();
    
    $term['vid'] = $vid;
    $term['format'] = 'plain_text';
    
    if (strpos($arg, '||') !== FALSE) {
      $term_arg = explode('||', $arg);
      
      $term['name'] = array_shift($term_arg);
    } else {
      $term['name'] = $arg;
    }
    
    foreach($term_arg as $ta) {
      if (preg_match('/^([A-Za-z]+)==(.+)$/', $ta, $matches)) {
        $key = $matches[1];
        $val = $matches[2];
        
        if (in_array($key, $term_keys)) {
          $term[$key] = $val;
        }
      }
    }
    
    if (in_array($term['vid'], $vids) && in_array($term['format'], $formats)) {
      $sql =
        'SELECT COUNT(*) '.
        'FROM {taxonomy_term_data} '.
        'WHERE `name` = :name '.
          'AND `vid` = :vid '.
        'ORDER BY `name`, `vid` '.
        'LIMIT 1;';
      $count = db_query($sql, array(':name' => $term['name'], ':vid' => $term['vid']))->fetchField();
      
      if (empty($count)) {
        $tid = db_insert('taxonomy_term_data')
        ->fields($term)
        ->execute();
        
        $insert = db_insert('taxonomy_term_hierarchy')
        ->fields(array('tid' => $tid))
        ->execute();
        
        $insert_count++;
      }
    }
  }
  
  if ($insert_count == 0) {
    $count_var = 'No taxonomy terms were';
  } elseif ($insert_count == 1) {
    $count_var = '1 taxonomy term was';
  } else {
    $count_var = $insert_count.' taxonomy terms were';
  }
  
  drush_print("\n".dt('!count_var added.', array('!count_var' => $count_var))."\n");
}

/**
 * Drush command callback for the OHO taxonomy show
 * terms command
 *
 * Lists names for all or some of the site's taxonomy
 * terms
 */
function drush_oho_core_oho_taxonomy_show_terms() {
  $query_args = $order_array = array();
  $where = '';
  $order = 'ORDER BY ';
  $limit = ';';
  
  $vocabularies_opt_list = drush_get_option_list('vocabularies');
  $order_opt_list = drush_get_option_list('sort');
  $limit_opt_list = drush_get_option_list('limit');
  
  // Set the WHERE clause if the vocabulary vids are specified
  if (is_string($vocabularies_opt_list)) {
    if (strpos($vocabularies_opt_list, ',') !== FALSE) {
      $vocabularies_opt_list = explode(',', $vocabularies_opt_list);
    }
  }
  
  if (!empty($vocabularies_opt_list)) {
    $where = 'WHERE `vid` ';
    
    if (is_array($vocabularies_opt_list)) {
      $where .= ' IN (:vid) ';
    } else {
      $where .= ' = :vid ';
    }
    
    $query_args[':vid'] = $vocabularies_opt_list;
  }
  
  // Set the ORDER BY clause
  if (!empty($order_opt_list) && is_array($order_opt_list)) {
    foreach ($order_opt_list as $order_opt) {      
      if (strpos($order_opt, '/') !== FALSE) {        
        list($order_by, $asc_desc) = explode('/', $order_opt);
        
        $sort_opts = array('ASC','asc','DESC','desc');

        if (in_array($asc_desc, $sort_opts)) {
          $order_asc_desc = strtoupper($asc_desc);
        } else {
          $order_asc_desc = 'ASC';
        }
      } else {
        $order_by = $order_opt;
        $order_asc_desc = 'ASC';
      }
      
      $order_array[$order_by] = '`'.$order_by.'` '.$order_asc_desc;
    }
  } else {
    $order_array['vid'] = '`vid` ASC';
    $order_array['name'] = '`name` ASC';
  }
  
  if (!empty($query_args[':vid'])) {
    if (!empty($order_array['vid'])) unset($order_array['vid']);
    $arr = array_reverse($order_array, TRUE);
    $arr['vid'] = '`vid` ASC';
    $order_array = array_reverse($arr, TRUE);
  }
  
  $order .= implode(',', $order_array);
  
  // Set the LIMIT clause
  if (!empty($limit_opt_list)) {
    $offset = '';
    $row_count = NULL;
    
    if (is_array($limit_opt_list)) {
      $row_count = array_shift($limit_opt_list);
      
      if (!empty($limit_opt_list)) {
        $offset = array_shift($limit_opt_list).', ';
      }
    } elseif (is_numeric($limit_opt_list)) {
      $row_count = $limit_opt_list;
      $offset = '';
    }
    
    $limit = ' LIMIT '.$offset.$row_count.';';
  }
  
  $sql =
    'SELECT `name` '.
    'FROM {taxonomy_term_data} '.$where.$order.$limit;
  $results = db_query($sql, $query_args);
  
  $msg = '';
  
  foreach ($results as $row) {
    $msg .= "\n".$row->name;
  }
  
  if (empty($msg)) {
    $msg = "\n".dt('No taxonomy terms were found with this query.');
  }
  
  $msg .= "\n";
  
  drush_print($msg);
}

/**
 * Drush command callback for the OHO taxonomy show
 * vocabularies command
 *
 * Lists all taxonomy vocabularies' machine_name and vid
 * values ordered by machine_name
 */
function drush_oho_core_oho_taxonomy_show_vocabularies() {
  if (db_table_exists('taxonomy_vocabulary')) {
    $sql =
      'SELECT `name`, `vid`, `machine_name` '.
      'FROM {taxonomy_vocabulary} '.
      'ORDER BY `name`;';
    $results = db_query($sql);
    
    foreach ($results as $row) {
      if (empty($msg)) $msg = '';
      
      $msg .= "\n".$row->name."\n\t".'machine_name = '.$row->machine_name."\n\t".'vid = '.$row->vid."\n";
    }
  }
  
  if (empty($msg)) {
    $msg = "\n".dt('There was no taxonomy vocabulary data available.')."\n";
  }
  
  drush_print($msg);
}

/**
 * Checks which Drupal version is in use
 */
function _oho_core_check_drupal_core($options = array(6 => 'Drupal 6.x', 7 => 'Drupal 7.x')) {
  if (!is_array($options) || empty($options)) {
    return 0;
  }
  
  $prompt = 'Enter a number to select your Drupal installation version.';
  
  return drush_choice($options, $prompt);
}