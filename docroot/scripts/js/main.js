(function($) {
  $.fn.ddNavToggle = function(options) {
    var $this = this,
        settings = $.extend({
          commonClass: 'main-nav-link',
          activeClass: 'active'
        }, options);
    
    $('.' + settings.commonClass).removeClass(settings.activeClass).trigger('blur');
    $('.main-nav-link[href="' + $this.attr('href') + '"]').addClass(settings.activeClass);
    
  }
})(jQuery);
(function($) {
  $(document).ready(function() {
    $('body').addClass('scrolling');
    
    var is_string = window.is_string,
        $overlayMenu = $('#overlay-menu'),
        dur_toggle = 250,
        win_height = $(window).outerHeight(),
        win_width = $(window).outerWidth(),
        width_cutoff_1 = 765;
    
    $('html').removeClass('no-js');
    $overlayMenu.css({'min-height': win_height + 'px'}).hide();
    
    $('a[href*=#]:not([href=#])').on('click', function() {
      var $this = $(this);
      
      if (!$(this).hasClass('no-scroll')) {
        if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
          var $target = $(this.hash);
          $target = $target.length ? $target : $('[id=' + this.hash.slice(1) +']');
          if ($target.length) {
            if ($('body').hasClass('scrolling')) return false;
            
            $('body').addClass('scrolling');
            $this.ddNavToggle();
            $overlayMenu.fadeOut(dur_toggle, function() {
              $('body').addClass('no-overlay');
            });
            
            $('html,body').animate({
              scrollTop: $target.offset().top
            }, 250, function() {
              $('body').removeClass('scrolling');
            });
            return false;
          }
        }
      }
    });
    
    // Scrolling helper
    function pageSection(key, top, height) {
      this.key = key;
      this.top = top;
      this.up = top + (height * 0.6);
      this.down = top - (height * 0.3);
    }
    
    var last_scrolltop = $(document).scrollTop(),
        $sections = $('body > section[id]'),
        $sectionFirst = $('body > section[id]:first'),
        $sectionLast = $('body > section[id]:last'),
        sections_data = [],
        last_up = 0;
    
    $sectionFirst.addClass('section-first');
    $sectionLast.addClass('section-last');
    
    var set_section_data = function() {
      $sections.each(function(index, value) {
        var $this = $(this),
            section_key = $this.attr('id').replace(/-[a-z]*$/, ''),
            section_top = parseInt($this.offset().top),
            section_height = $this.outerHeight(true);
        
        sections_data[index] = new pageSection(section_key, section_top, section_height);
        
        if ($this.hasClass('section-first')) {
          sections_data[index].down = 0;
        }
        else if ($this.hasClass('section-last')) {
          sections_data[index].up = 0;
        }
      });
    }
    
    set_section_data();
    
    $(window).resize(function() {
      win_height = $(window).outerHeight();
      win_width = $(window).outerWidth();
      $overlayMenu.css({'min-height': win_height + 'px'});
      set_section_data();
    });
    
    var last_section_key = 'portfolio';
    
    $(document).scroll(function() {
      if ($('body').hasClass('scrolling')) return;
      
      var current_scrolltop = $(document).scrollTop(),
          to_trigger = '',
          scrolling_down = (current_scrolltop > last_scrolltop);
      
      if (current_scrolltop == 0) return;
      
      // Update the last scroll top
      last_scrolltop = current_scrolltop;
      
      for (var i = 0; i < sections_data.length; i++) {
        if ((scrolling_down && current_scrolltop > sections_data[i].down && current_scrolltop < sections_data[i].top) || (!scrolling_down && current_scrolltop < sections_data[i].up && current_scrolltop > sections_data[i].top)) {
          // Prevent attempting to scroll to the currently visible section
          if (sections_data[i].key == last_section_key) return;
          
          to_trigger = sections_data[i].key;
          last_section_key = to_trigger;
          break;
        }
      }
      
      if (is_string(to_trigger)) {
        var $triggerLink = $('#fixed-menu-buttons .button-link.' + to_trigger);
        /*if (win_width > width_cutoff_1) {
          $triggerLink.trigger('click');
        }
        else {*/
          $triggerLink.ddNavToggle();
        //}
      }
    });
    
    $('.close-me').on('click', function() {
      $($(this).attr('href')).fadeToggle(dur_toggle);
      $('body').addClass('no-overlay');
      return false;
    });
    
    $('#popout-nav-toggle').on('click', function() {
      win_height = $(window).height;
      $overlayMenu.css({'height': win_height + 'px'}).fadeToggle(dur_toggle);
      $('body').removeClass('no-overlay');
      return false;
    });
    
    // Home slideshow
    $('#portfolio-slider-wrapper').ddXMLSlider('/xml/slides.xml', {
      slideshow: 'home',
      auto_slide: false
    });
    
    // Contact form
    $('.form-submit').on('click', function() {
      var $button = $(this),
          $form = $($button.attr('href'))
          $mssgDiv = $($button.attr('data-messages'));
      
      if (!$form.length) {
        return false;
      }
      
      var post_data = $form.serializeArray(),
          form_url = $form.attr('action');
      
      $.ajax({
        url: form_url,
        type: "POST",
        data: post_data,
        success: function(data, textStatus, jqXHR) {
          var obj = $.parseJSON(data);
          
          $form.find('*').removeClass('error');
          $mssgDiv.html('').slideUp(150);
          
          if (typeof obj.errors == 'object') {
            $.each(obj.errors, function(index, value) {
              var $field = $form.find('*[name="' + index + '"]');
              $field.addClass('error');
              $mssgDiv.append('<p class="error-' + index + '">' + value + '</p>');
              $field.on('keyup', function() {
                $field.removeClass('error');
                $mssgDiv.find('.error-' + $field.attr('name')).remove();
              });
            });
            
            $mssgDiv.slideDown(150);
          }
          else if (typeof obj.message == 'string') {
            $form.fadeOut(150, function() {
              $form.html('<div class="form-messages"><p class="success">' + obj.message + '</p></div> <!-- /.form-messages -->');
              $form.fadeIn(150, function() {
                $mssgDiv.fadeIn(150);
              });
            });
          }
        },
        error: function(jqXHR, textStatus, errorThrown) {
          console.log('error!');
          console.log(jqXHR);
          console.log(textStatus);
          console.log(errorThrown);
        }
      });
      
      return false;
    });
    
    $('body').removeClass('scrolling');
  });
})(jQuery);
