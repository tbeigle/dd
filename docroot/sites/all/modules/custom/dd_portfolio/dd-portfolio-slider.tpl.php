<?php
/**
 * @file dd-portfolio-slider.tpl.php
 *
 * Available variables:
 *
 * - $slides: An array containing rendered slides
 */
?>
<h1 id="logo-title">
  <span class="title-text">Designated Developers</span>
  <img id="logo" class="block-auto" src="<?php print $path; ?>/images/logo-watermark.png" alt="Watermark logo for Designated Developers">
</h1>

<?php if (!empty($slides)): ?>
  <h2 id="portfolio-title" class="portfolio-top-text">We create <strong>amazing</strong> things.</h2>
  <h3 id="portfolio-subhead" class="portfolio-top-text">See them in action.</h3>
  <a class="scroll-nav-link portfolio block-auto glyph scroll-link" href="#portfolio-slider-wrapper" tabindex="6">&iacute;</a>
  
  <div id="portfolio-slider-wrapper">
    <div id="portfolio-slider-bg"></div>
    <div class="slider-wrapper">
      <div class="slider">
        <ul class="slides">
          <?php foreach ($slides as $index => $slide): ?>
            <li class="slide slide-<?php print $index; ?>">
              <img src="<?php print $slide->img['src']; ?>" alt="<?php print $slide->img['alt']; ?>">
              <div class="element-invisible caption-markup">
                <h2 class="slide-title">
                  <a href="<?php print $slide->url; ?>" target="_blank"><?php print $slide->title; ?></a>
                </h2> <!-- /.slide-title -->
                
                <div class="slide-caption"><?php print $slide->caption; ?></div>
              </div> <!-- /.caption-markup -->
            </li> <!-- /.slide -->
          <?php endforeach; ?>
        </ul> <!-- /.slides -->
      </div> <!-- /.slider -->
    </div> <!-- /.slider-wrapper -->
    
    <div class="slider-caption" style="display: none;"></div>
    <div class="slider-testimonial" style="display: none;"></div>
  </div> <!-- /#portfolio-slider-wrapper -->
<?php endif; ?>
