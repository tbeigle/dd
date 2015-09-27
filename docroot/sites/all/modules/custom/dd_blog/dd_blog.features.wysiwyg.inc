<?php
/**
 * @file
 * dd_blog.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function dd_blog_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: advanced
  $profiles['advanced'] = array(
    'format' => 'advanced',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 1,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Image' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Source' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'ShowBlocks' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'Font' => 1,
          'FontSize' => 1,
          'Styles' => 1,
          'Table' => 1,
          'Flash' => 1,
          'CreateDiv' => 1,
          'Iframe' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '%b%t/assets/css/editor.css',
      'css_classes' => 'Blog IMG Left=img.blog-post-img-left
Blog P Left=p.blog-post-img-left
Blog DIV Left=p.blog-post-img-left
Blog Cutline Left=p.img-cutline-left',
    ),
  );

  return $profiles;
}
