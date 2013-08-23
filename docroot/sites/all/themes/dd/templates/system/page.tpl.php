<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<?php if ($logo || $page['header'] || $main_menu || $page['nav']): ?>
  <header id="header" class="clearfix">
    <div class="container row clearfix">
      <div class="row clearfix">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
        
        <?php if ($page['header']): ?>
          <div id="region-header-wrapper" class="right">
            <?php print render($page['header']); ?>
          </div>
          <!-- /#region-header-wrapper /.right -->
        <?php endif; ?>
        
        <?php if ($main_menu || $page['nav']): ?>
          <nav id="primary-navigation" class="clearfix row">
            <?php if ($page['nav']): ?>
              <?php print render($page['nav']); ?>
            <?php else: ?>
              <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
            <?php endif; ?>
          </nav>
          <!-- /#primary-navigation /.clearfix /.row -->
        <?php endif; ?>
      </div>
      <!-- /.row /.clearfix -->
    </div>
    <!-- /.container /.row /.clearfix -->
  </header>
  <!-- /#header /.clearfix -->
<?php endif; ?>

<?php if ($breadcrumb && !$hide_breadcrumb): ?>
  <div id="breadcrumb" class="container row clearfix">
    <div class="row clearfix">
      <?php print $breadcrumb; ?>
    </div>
    <!-- /.row /.clearfix -->
  </div>
  <!-- /#breadcrumb /.container /.row /.clearfix -->
<?php endif; ?>

<?php if (!empty($messages)): ?>
  <div id="dd-messages-wrapper" class="container row clearfix">
    <div class="row clearfix">
      <?php print $messages; ?>
    </div>
    <!-- /.row /.clearfix -->
  </div>
  <!-- /#dd-messages-wrapper /.container /.row /.clearfix -->
<?php endif; ?>

<div id="main-wrapper" class="container row clearfix">
  <?php if ($tabs || !empty($page['help'])): ?>
    <div id="dd-tabs-and-help" class="row clearfix">
      <?php if ($tabs): ?>
        <div class="tabs"><?php print render($tabs); ?></div>
      <?php endif; ?>
      
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      
      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>
    </div>
    <!-- /#dd-tabs-and-help /.row /.clearfix -->
  <?php endif; ?>
  
  <div id="main" class="row clearfix">
    <?php if ($page['sidebar_first']): ?>
      <div id="dd-sidebar-first" class="column">
        <?php print render($page['sidebar_first']); ?>
      </div>
      <!-- /#dd-sidebar-first /.column -->
    <?php endif; ?>
    
    <div id="content-wrapper" class="column">
      <a id="main-content"></a>
      
      <?php if ($page['content_top'] || $title): ?>
        <div id="dd-content-top" class="row clearfix">
          <?php print render($title_prefix); ?>
          <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php print render($title_suffix); ?>
          
          <?php if ($page['content_top']): ?>
            <?php print render($page['content_top']); ?>
          <?php endif; ?>
        </div>
        <!-- /#dd-content-top /.row /.clearfix -->
      <?php endif; ?>
      
      <div id="content" class="row clearfix">
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div>
      <!-- /#content /.row /.clearfix -->
      
      <?php if ($page['content_bottom']): ?>
        <div id="dd-conent-bottom" class="row clearfix">
          <?php print render($page['content_bottom']); ?>
        </div>
        <!-- /#content-bottom /.row /.clearfix -->
      <?php endif; ?>
    </div>
    <!-- /#content-wrapper /.column -->
    
    <?php if ($page['sidebar_second']): ?>
      <div id="dd-sidebar-second" class="column">
        <?php print render($page['sidebar_second']); ?>
      </div>
      <!-- /#dd-sidebar-second /.column -->
    <?php endif; ?>
  </div>
  <!-- #main /.row /.clearfix -->
</div>
<!-- /#main-wrapper /.container /.row /.clearfix -->

<footer id="footer" class="row clearfix container">
  <div class="section row clearfix">
    <?php if ($page['footer']): ?>
      <?php print render($page['footer']); ?>
    <?php endif; ?>
    <p class="copyright">&copy; <?php print date('Y'); ?> Designated Developers, All Rights Reserved</p>
  </div>
  <!-- /.section /.row /.clearfix -->
</footer>
<!-- /#footer /.container /.row /.clearfix -->
