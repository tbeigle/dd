(function($) {
  $(document).ready(function() {
    $('[placeholder]').focus(function() {
      var $input = $(this);
      
      if ($input.val() == $input.attr('placeholder')) {
        $input.val('');
      }
    })
    .blur(function() {
      var $input = $(this);
      
      if ($input.val() == '') {
        $input.val($input.attr('placeholder'));
      }
    })
    .blur();
  });
})(jQuery);
