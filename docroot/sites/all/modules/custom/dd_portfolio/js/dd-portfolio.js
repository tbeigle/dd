(function($) {
  $.fn.hasTestimonial = function() {
    var $this = this,
        $tdata = {
          q: {
            k: 'tquote',
            has: false
          },
          s: {
            k: 'tsource',
            has: false
          }
        };
    
    for (i in $tdata) {
      var dk = 'data-' + $tdata[i].k;
      if (typeof $this.attr(dk) !== 'undefined' && typeof $this.attr(dk) !== false) {
        $tdata[i].has = $this.attr(dk).length;
      }
    }
    
    return ($tdata.q.has && $tdata.s.has);
  }
  
  $.fn.ddPortfolioSlider = function(options) {
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
        slider_id = 'dd-slider-' + settings.slideshow;
    
    $this.find('.slider-wrapper').attr('id', slider_id);
    
    var slide_count = 0,
        base_markup = '',
        nav_markup = '',
        slide_horizontal = (settings.view == 'horizontal'),
        slider_width = settings.slider_width,
        slider_height = settings.slider_height,
        $sliderWrapper = $('#' + slider_id),
        $sliderOuter = $sliderWrapper.find('.slider'),
        $slider = $sliderWrapper.find('.slider .slides'),
        $caption = $this.children('.slider-caption'),
        $testimonial = $this.children('.slider-testimonial'),
        $slides = $slider.find('.slide'),
        slide_count = $slides.length;
    
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
        
        $testimonial.fadeOut(settings.spd, function() {
          /*var thtml = '';
          if ($newSlide.hasTestimonial()) {
            $testimonial.addClass('show-testimonial');
            thtml = '<em>"' + $newSlide.attr('data-tquote') + '"</em> <strong>- ' + $newSlide.attr('data-tsource') + '</strong>';
          }
          else {
            $testimonial.removeClass('show-testimonial');
          }
          $testimonial.html(thtml);*/
        });
        
        $caption.fadeOut(settings.spd, function() {
          caption_markup = $newSlide.find('.caption-markup').html();
          $caption.html(caption_markup);
          $caption.fadeIn(settings.spd);
        });
        
        return false;
      });
    }
    
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
    
    var caption_markup = $activeSlide.find('.caption-markup').html();
    $caption.html(caption_markup);
    
    // Testimonial
    /*var thtml = '';
    if ($activeSlide.hasTestimonial()) {
      $testimonial.addClass('show-testimonial');
      thtml = '<em>"' + $activeSlide.attr('data-tquote') + '"</em> <strong>- ' + $activeSlide.attr('data-tsource') + '</strong>';
    }
    $testimonial.html(thtml);*/

    $slides.css({'max-width': slider_width});
    
    $slider.fadeIn(settings.spd);
    $caption.fadeIn(settings.spd);
    
    if (slider_width < settings.slider_width) {
      //slider_height = $slides.height();
      //$slider.height(slider_height);
    }
  }
  
  Drupal.behaviors.ddPortfolio = {
    attach: function(context, settings) {
      $('#portfolio-slider-wrapper').ddPortfolioSlider();
    }
  }
})(jQuery);
