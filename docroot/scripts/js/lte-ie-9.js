(function($) {
  $(document).ready(function() {
    var ph_class = 'ie-placeholder';
    
    $('[placeholder]').focus(function() {
      var $input = $(this);
      
      if ($input.val() == $input.attr('placeholder')) {
        $(this).removeClass(ph_class).val('');
      }
    })
    .blur(function() {
      var $input = $(this);
      
      if ($input.val() == '') {
        $input.addClass(ph_class).val($input.attr('placeholder'));
      }
    })
    .blur();
  });
})(jQuery);
