/**
 * Check whether an element is a string with a length greater than 0
 */
function is_string(str) {
  if (typeof str != 'string') {
    return false;
  }
  
  return str.length;
}

(function($) {
  Drupal.behaviors.dd = {
    attach: function(context, settings) {
      function remove_hash () { 
        var scrollV,
            scrollH,
            loc = window.location,
            $target = $(loc.hash);
          
        $target = $target.length ? $target : $('[id=' + loc.hash.slice(1) +']');
        if ($target.length) {
          if (!$('body').hasClass('scrolling')) $('body').addClass('scrolling');
          
          $('html,body').animate({
            scrollTop: $target.offset().top
          }, 250, function() {
            $('body').removeClass('scrolling');
          });
        }
        /*
        if ('pushState' in history) {
          history.pushState("", document.title, loc.pathname + loc.search);
        }
        else {
          // Prevent scrolling by storing the page's current scroll offset
          scrollV = document.body.scrollTop;
          scrollH = document.body.scrollLeft;
      
          loc.hash = '';
      
          // Restore the scroll offset, should be flicker free
          document.body.scrollTop = scrollV;
          document.body.scrollLeft = scrollH;
        }
        */
      }
      
      if (('#fixed-menu-buttons').length && !$('#fixed-menu-buttons .menu-buttons li').length) {
        // Add the main-nav-link class to the flyout nav items
        $('#overlay-menu .block-menu .content .menu li a').addClass('main-nav-link');
        // Build the section dots
        var dot_counter = 2;
        $('#overlay-menu .block-menu .content .menu li a[href*=#]:not([href=#])').each(function(index, value) {
          var $this = $(this),
              sk = $this.attr('href').replace(/-[a-z]*$/, '');
          sk = sk.replace(/^#/, '');
          
          if (sk == 'dd-slider') {
            sk = 'portfolio active';
          }
          
          $this.attr('class', 'button-link main-nav-link ' + sk + ' scroll-link');
          
          var dot_html = '<li>';
          dot_html += '<a class="button-link main-nav-link ' + sk + ' scroll-link" ';
          dot_html += 'href="' + $this.attr('href') + '" ';
          dot_html += 'tabindex="' + dot_counter + '">' + $(this).text() + '</a></li>';
          $('#fixed-menu-buttons .menu-buttons').append(dot_html);
          
          $this.attr('class', 'button-link main-nav-link ' + sk + ' scroll-link');
          ++dot_counter;
        });
      }
      
      $.fn.ddNavToggle = function(options) {
        var $this = this,
            settings = $.extend({
              commonClass: 'main-nav-link',
              activeClass: 'active'
            }, options);
        
        $('.' + settings.commonClass).removeClass(settings.activeClass).trigger('blur');
        $('.main-nav-link[href="' + $this.attr('href') + '"]').addClass(settings.activeClass);
      }
      
      $('body').addClass('scrolling');
      
      var is_string = window.is_string,
          $overlayMenu = $('#overlay-menu'),
          dur_toggle = 250,
          win_height = $(window).outerHeight(),
          win_width = $(window).outerWidth(),
          width_cutoff_1 = 765;
      
      remove_hash();
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
          $sections = $('.scrollto-section'),
          $sectionFirst = $('.scrollto-section:first'),
          $sectionLast = $('.scrollto-section:last'),
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
      
      if (typeof last_section_key === 'undefined') {
        var last_section_key = 'block-dd-portfolio-slider';
      }
      
      if ($('#wwd-container').length) {
        var wwdoff = $('#wwd-container').offset(),
            wwdbottomcut = wwdoff.top + $('#wwd-container').outerHeight() - 67,
            wwdtitleheight = $('#wwd-title').outerHeight(),
            wwdcutoff = wwdbottomcut - wwdtitleheight;
      }
      
      $(document).scroll(function() {
        if ($('body').hasClass('scrolling')) return;
        
        var current_scrolltop = $(document).scrollTop(),
            to_trigger = '',
            scrolling_down = (current_scrolltop > last_scrolltop),
            scroll_bottom = current_scrolltop + $(window).height();
        
        if (current_scrolltop == 0) return;
        
        if ($('#wwd-container').length) {
          if (current_scrolltop > wwdoff.top) {
            if (scroll_bottom < wwdbottomcut) {
              $('body').removeClass('show-wwd-title-bottom').addClass('show-wwd-title-fixed');
            }
            else {
              $('body').removeClass('show-wwd-title-fixed').addClass('show-wwd-title-bottom');
            }
          }
          else {
            $('body').removeClass('show-wwd-title-fixed').removeClass('show-wwd-title-bottom');
          }
        }
        
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
          $triggerLink.ddNavToggle();
        }
      });
      
      $('.close-me').on('click', function() {
        $($(this).attr('href')).fadeOut(dur_toggle);
        $('body').addClass('no-overlay');
        $('#popout-nav-toggle').show();
        return false;
      });
      
      $('#popout-nav-toggle').on('click', function() {
        win_height = $(window).height;
        $overlayMenu.css({'height': win_height + 'px'}).fadeIn(dur_toggle);
        $('body').removeClass('no-overlay');
        $(this).hide();
        return false;
      });
      
      $('body').removeClass('scrolling');
    }
  };
})(jQuery);
