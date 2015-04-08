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
  <div id="wwa-bios" class="row<?php if (!empty($header)) print ' with-header'; ?>">
    <?php if (!empty($header)): ?>
      <div id="wwa-header" class="row">
        <h4 class="wwa-heading"><?php print $wwahead; ?></h4>
        
        <?php print $header; ?>
      </div> <!-- /#wwa-header /.row -->
    <?php endif; ?>
    
    <?php foreach ($people as $index => $row): ?>
      <div class="row row-<?php print $index; ?>">
        <?php foreach ($row as $person): ?>
          <div class="<?php print $person->css_class; ?>">
            <h4 class="wwa-heading"><?php print $wwahead; ?></h4>
            
            <h2 class="wwa-name"><?php print $person->name; ?><?php if (!empty($person->position)): ?><div class="wwa-heading"><?php print $person->position; ?></div><?php endif; ?></h2>
            
            
            <div class="wwa-bio"><?php print $person->bio; ?></div>
            
            <?php if (!empty($person->link)): ?>
              <?php print $person->link; ?>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endforeach; ?>
  </div> <!-- /#wwa-bios -->
<?php endif; ?>
