(function($) {
  $.fn.ddXMLSlider = function(xml_path, options) {
    var is_string = window.is_string;
    
    if (!is_string(xml_path)) return;
    
    var settings = $.extend({
      slideshow: 'home',
      dur: 3000,
      spd: 250,
      auto_slide: false,
      slider_width: 530,
      slider_height: 331,
      view: 'horizontal',
      caption_wrapper: '',
      arrow_text: {
        prev: 'Previous',
        next: 'Next'
      }
    }, options);
    
    var $this = this,
        slider_id = 'dd-slider-' + settings.slideshow,
        slide_count = 0,
        base_markup = '',
        nav_markup = '',
        slide_horizontal = (settings.view == 'horizontal');
    
    base_markup += '<div id="' + slider_id + '" class="slider-wrapper"><div class="slider"><ul class="slides" style="display: none;"></ul></div></div>';
    
    if (!settings.caption_wrapper.length) {
      base_markup += '<div class="slider-caption" style="display: none;"><h2 class="slide-title"></h2>' + "\n" + '<h3 class="slide-caption"></h3></div>';
    }
    
    $this.append(base_markup);
    
    var $sliderWrapper = $('#' + slider_id),
        $slider = $sliderWrapper.find('.slider .slides'),
        $caption = $this.children('.slider-caption'),
        slide_markup = '';
    
    // Load the XML file
    $.get(xml_path, function(xml) {
      var $xml = $(xml),
          $slideshow = $xml.find('show[page="' + settings.slideshow + '"]'),
          slide_count = 0,
          slide_class = '';
      
      $slideshow.find('slide').each(function(index, value) {
        var $slide = $(value);
        
        slide_class = 'slide-' + index;
        slide_markup += '<li class="slide ' + slide_class + '" ';
        slide_markup += 'data-title="' + $slide.find('title').text() + '" ';
        slide_markup += 'data-caption="' + $slide.find('caption').text() + '">';
        slide_markup += '<img src="' + $slide.attr('src') + '" alt="' + $slide.attr('alt') + '">';
        slide_markup += '</li>';
        ++slide_count;
      });
      
      if (slide_count > 1) {
        if (slide_horizontal) {
          var slides_width = settings.slider_width * slide_count;
          $slider.width(slides_width);
        }
        
        nav_markup += '<nav class="slider-nav">' + "\n\t";
        nav_markup += '<ul class="arrows">' + "\n\t\t";
        nav_markup += '<li class="slider-nav-item previous">' + "\n\t\t\t";
        nav_markup += '<a class="slider-nav-arrow hidden" title="Previous Slide" data-direction="previous" href="#" style="display: none;">' + settings.arrow_text.prev + '</a>' + "\n\t\t";
        nav_markup += '</li>' + "\n\t\t";
        nav_markup += '<li class="slider-nav-item next">' + "\n\t\t\t";
        nav_markup += '<a class="slider-nav-arrow" title="Next Slide" data-direction="next" href="#">' + settings.arrow_text.next + '</a>' + "\n\t\t";
        nav_markup += '</li>' + "\n\t";
        nav_markup += '</ul>' + "\n";
        nav_markup += '</nav>';
        
        $sliderWrapper.prepend(nav_markup);
        
        var $sliderNav = $sliderWrapper.find('.slider-nav');
        $sliderNav.fadeIn(settings.spd);
        
        $('#' + slider_id + ' .slider-nav-item a').on('click', function() {
          var $this = $(this),
              slide_direction = $this.attr('data-direction'),
              $curSlide = $('.slide.active'),
              $newSlide,
              $otherLink,
              animate_operator = '-=';
          
          switch (slide_direction) {
            case 'previous':
              $otherLink = $('#' + slider_id + ' .slider-nav-item.next .slider-nav-arrow');
              $newSlide = $curSlide.prev();
              animate_operator = '+=';
              break;
            case 'next':
              $otherLink = $('#' + slider_id + ' .slider-nav-item.previous .slider-nav-arrow');
              $newSlide = $curSlide.next();
              break;
          }
          
          if (typeof $newSlide == 'undefined') return false;
          
          $curSlide.removeClass('active');
          $newSlide.addClass('active');
          
          if ((slide_direction == 'previous' && $newSlide.is('li:first-child')) || (slide_direction == 'next' && $newSlide.is('li:last-child'))) {
            $this.fadeOut(settings.spd, function() {
              $this.addClass('hidden');
            });
          }
          
          if ($otherLink.hasClass('hidden')) {
            $otherLink.fadeIn(settings.spd, function() {
              $otherLink.removeClass('hidden');
            });
          }
          
          var animate_options = slide_horizontal ? {left: animate_operator + settings.slider_width} : {top: animate_operator + settings.slider_height};
          $slider.children('.slide').animate(animate_options, settings.spd);
          
          $caption.fadeOut(settings.spd, function() {
            $caption.find('.slide-title').text($newSlide.attr('data-title'));
            $caption.find('.slide-caption').text($newSlide.attr('data-caption'));
            
            $caption.fadeIn(settings.spd);
          });
          
          return false;
        });
      }
      
      $slider.append(slide_markup);
      var $activeSlide = $slider.children('li:first-child');
      $activeSlide.addClass('active');
      
      $caption.find('.slide-title').text($activeSlide.attr('data-title'));
      $caption.find('.slide-caption').text($activeSlide.attr('data-caption'));
      
      $slider.fadeIn(settings.spd);
      $caption.fadeIn(settings.spd);
    });
  }
})(jQuery);
