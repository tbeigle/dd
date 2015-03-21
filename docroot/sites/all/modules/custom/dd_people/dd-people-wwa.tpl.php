<?php
/**
 * @file dd-people-wwa.tpl.php
 *
 * Available variables:
 *
 * - $people: An array of employee objects
 */
?>

<?php if (!empty($people)): ?>
  <div id="wwa-bios" class="row">
    <?php foreach ($people as $index => $row): ?>
      <div class="row row-<?php print $index; ?>">
        <?php foreach ($row as $person): ?>
          <div class="<?php print $person->css_class; ?>">
            <h4 class="wwa-heading"><?php print t('Who We Are'); ?></h4>
            
            <h2 class="wwa-name"><?php print $person->name; ?></h2>
            
            <div class="wwa-bio"><?php print $person->bio; ?></div>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endforeach; ?>
  </div> <!-- /#wwa-bios -->
<?php endif; ?>
