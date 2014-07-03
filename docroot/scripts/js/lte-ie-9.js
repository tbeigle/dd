(function($) {
  $.fn.ieplaceholder = function(h) {
    var $input = this,
        ph_class = 'ie-placeholder';
    
    if (h == 'keydown' || ($input.val() != $input.attr('placeholder') && $input.val() != '')) {
      $input.removeClass(ph_class);
      
      if ($input.val() == $input.attr('placeholder')) {
        $input.val('');
      }
    }
    else if ($input.val() == '') {
      $input.addClass(ph_class).val($input.attr('placeholder'));
    }
  };
  
  $(document).ready(function() {
    $('[placeholder]').keydown(function() {
      $(this).ieplaceholder('keydown');
    })
    .keyup(function() {
      $(this).ieplaceholder();
    })
    .blur(function() {
      $(this).ieplaceholder();
    })
    .blur();
  });
})(jQuery);
