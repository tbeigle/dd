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
        slide_horizontal = (settings.view == 'horizontal'),
        slider_width = settings.slider_width,
        slider_height = settings.slider_height;
    
    base_markup += '<div id="' + slider_id + '" class="slider-wrapper"><div class="slider"><ul class="slides" style="display: none;"></ul></div></div>';
    
    if (!settings.caption_wrapper.length) {
      base_markup += '<div class="slider-caption" style="display: none;"><h2 class="slide-title"></h2>' + "\n" + '<h3 class="slide-caption"></h3></div>';
    }
    
    base_markup += '<div class="slider-testimonial" style="display: none;"></div>';
    
    $this.append(base_markup);
    
    var $sliderWrapper = $('#' + slider_id),
        $sliderOuter = $sliderWrapper.find('.slider-wrapper .slider'),
        $slider = $sliderWrapper.find('.slider .slides'),
        $caption = $this.children('.slider-caption'),
        $testimonial = $this.children('.slider-testimonial'),
        slide_markup = '',
        $slides;
    
    // Load the XML file
    $.get(xml_path, function(xml) {
      var $xml = $(xml),
          $slideshow = $xml.find('show[page="' + settings.slideshow + '"]'),
          slide_count = 0,
          slide_class = '';
      
      $slideshow.find('slide').each(function(index, value) {
        var $slide = $(value),
            $title = $slide.find('title');
        
        slide_class = 'slide-' + index;
        slide_markup += '<li class="slide ' + slide_class + '" ';
        slide_markup += 'data-title="' + $title.text() + '" ';
        slide_markup += 'data-url="' + $title.attr('url') + '" ';
        
        if ($slide.find('testimonial').length) {
          var $testimonial = $slide.find('testimonial');
          slide_markup += 'data-tquote="' + $testimonial.find('quote').text() + '" ';
          slide_markup += 'data-tsource="' + $testimonial.find('source').text() + '" ';
        }
        
        slide_markup += 'data-caption="' + $slide.find('caption').text() + '">';
        slide_markup += '<img src="' + $slide.attr('src') + '" alt="' + $slide.attr('alt') + '">';
        slide_markup += '</li>';
        ++slide_count;
      });
      
      if ($('body').width() < settings.slider_width) {
        slider_width = $('body').width();
      }
      
      var slides_width = slider_width * slide_count;
      
      $slider.width(slides_width);
      
      $(window).resize(function() {
        if ($('body').width() < settings.slider_width) {
          slider_width = $('body').width();
        }
        else {
          slider_width = settings.slider_width;
        }
        
        $slides.css({'max-width': slider_width});
        //slider_height = $slides.height();
        slides_width = slider_width * slide_count;
        //$slider.height(slider_height);
        $slider.width(slides_width);
      });
      
      if (slide_count > 1) {
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
        
        $('#' + slider_id + ' .slider-nav-item a, #' + slider_id + ' .slider .slides').on('click', function() {
          var $this = $(this),
              slider_clicked = $this.is('.slides'),
              $curSlide = $('.slide.active'),
              $curLink = $('#' + slider_id + ' .slider-nav-item.next .slider-nav-arrow'),
              $firstSlide = $('.slide:first-child'),
              $newSlide,
              $otherLink,
              animate_operator = '-=',
              on_last_slide = $curSlide.is('li:last-child'),
              slide_direction = 'next';
          
          if ($this.attr('data-direction')) {
            slide_direction = $this.attr('data-direction');
            $curLink = $this;
          }
          else if ($curSlide.is('li:last-child')) {
            slide_direction = 'previous';
            $curLink = $('#' + slider_id + ' .slider-nav-item.previous .slider-nav-arrow');
          }
          
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
          
          if (on_last_slide && slider_clicked) $newSlide = $firstSlide;
          
          if (typeof $newSlide == 'undefined') return false;
          
          $curSlide.removeClass('active');
          $newSlide.addClass('active');
          
          if ((slide_direction == 'previous' && $newSlide.is('li:first-child')) || (slide_direction == 'next' && $newSlide.is('li:last-child'))) {
            $curLink.fadeOut(settings.spd, function() {
              $curLink.addClass('hidden');
            });
          }
          
          if ($otherLink.hasClass('hidden')) {
            $otherLink.fadeIn(settings.spd, function() {
              $otherLink.removeClass('hidden');
            });
          }
          
          if (on_last_slide && slider_clicked) {
            $slider.children('.slide').animate({left: 0}, settings.spd);
          }
          else {
            $slider.children('.slide').animate({left: animate_operator + slider_width}, settings.spd);
          }
          
          $tesimonial.fadeOut(settings.spd, function() {
            var has_quote = (typeof $newSlide.attr('data-tquote') !== undefined && typeof $newSlide.attr('data-tquote') !== false && $newSlide.attr('data-tquote').length);
            var has_source = (typeof $newSlide.attr('data-tsource') !== undefined && typeof $newSlide.attr('data-tsource') !== false && $newSlide.attr('data-tsource').length);
            var thtml = '';
            
            if (has_quote && has_source) {
              $testimonial.addClass('show-testimonial');
              thtml = '<em>"' + $newSlide.attr('data-tquote') + '"</em> <strong>- ' + $newSlide.attr('data-tsource') + '</strong>';
            }
            else {
              $testimonial.removeClass('show-testimonial');
            }
            
            $testimonial.html(thtml);
          });
          $caption.fadeOut(settings.spd, function() {
            var new_title = '';
            if ($newSlide.attr('data-url').length) {
              new_title = '<a href="' + $newSlide.attr('data-url') + '" target="_blank">' + $newSlide.attr('data-title') + '</a>';
            }
            else {
              new_title = $newSlide.attr('data-title');
            }
            
            $caption.find('.slide-title').text(new_title);
            $caption.find('.slide-caption').text($newSlide.attr('data-caption'));
            
            $caption.fadeIn(settings.spd);
          });
          
          return false;
        });
      }
      
      $slider.append(slide_markup);
      $slides = $slider.find('.slide');
      $slides.mouseenter(function() {
        if($testimonial.hasClass('show-testimonial')) {
          $testimonial.fadeIn(settings.spd)
        }
      })
      .mouseleave(function() {
        $testimonial.fadeOut(settings.spd);
      });
      
      var $activeSlide = $slider.children('li:first-child');
      $activeSlide.addClass('active');
      
      var new_title = '';
      if ($activeSlide.attr('data-url').length) {
        new_title = '<a href="' + $activeSlide.attr('data-url') + '" target="_blank">' + $activeSlide.attr('data-title') + '</a>';
      }
      else {
        new_title = $activeSlide.attr('data-title');
      }
      
      $caption.find('.slide-title').html(new_title);
      $caption.find('.slide-caption').html($activeSlide.attr('data-caption'));
      
      var has_quote = (typeof $activeSlide.attr('data-tquote') !== undefined && typeof $activeSlide.attr('data-tquote') !== false && $activeSlide.attr('data-tquote').length);
      var has_source = (typeof $activeSlide.attr('data-tsource') !== undefined && typeof $activeSlide.attr('data-tsource') !== false && $activeSlide.attr('data-tsource').length);
      var thtml = '';
      
      if (has_quote && has_source) {
        $testimonial.addClass('show-testimonial');
        thtml = '<em>"' + $activeSlide.attr('data-tquote') + '"</em> <strong>- ' + $activeSlide.attr('data-tsource') + '</strong>';
      }
      $testimonial.html(thtml);
      
      $slides.css({'max-width': slider_width});
      
      $slider.fadeIn(settings.spd);
      $caption.fadeIn(settings.spd);
      
      if (slider_width < settings.slider_width) {
        //slider_height = $slides.height();
        //$slider.height(slider_height);
      }
    });
  }
})(jQuery);
