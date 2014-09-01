<!DOCTYPE html>
<!--[if lte IE 9]> <html class="lte-ie-9 no-js"> <![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)|!(IEMobile)|!(IE)]><!--><html dir="ltr" lang="en-US" class="no-js"><!--<![endif]-->
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Designated Developers | Internship Application</title>
    <meta name="description" content="Designated Developers is a Web development firm focused on swift, detail-oriented delivery of market-facing Drupal websites.">
    <link href='http://fonts.googleapis.com/css?family=Source+Sans+Pro:200,300,400,600,700,900' rel='stylesheet' type='text/css'>
    <link href="/styles/css/dd.css" rel="stylesheet">
    <script>
      (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
      (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
      m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
      })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
      
      ga('create', 'UA-44636522-1', 'designated-developers.com');
      ga('send', 'pageview');
    </script>
  </head>
  <body class="no-overlay">
    <section id="ttu-container">
      <h1 id="logo-title">
        <span class="title-text">Designated Developers</span>
        <img id="logo" class="block-auto" src="/images/logo-watermark.png" alt="Watermark logo for Designated Developers">
      </h1>
      
      <h2 id="portfolio-title" class="portfolio-top-text">We create <strong>amazing</strong> things.</h2>
      <h3 id="portfolio-subhead" class="portfolio-top-text">If you intern with us, so will you.</h3>
      
      <a class="scroll-nav-link portfolio block-auto glyph scroll-link" href="#intern-form" tabindex="6">&iacute;</a>
      
      <form name="internForm" id="intern-form" class="block-auto" method="post" action="/includes/internship-application-submit.php" enctype="multipart/form-data">
        <input type="hidden" name="subject" value="Internship Application">
        <div class="form-messages"></div> <!-- /.form-messages -->
        <input type="text" name="name" id="field-name" class="textfield placeholder-label block-auto required" placeholder="What is your name?">
        <input type="email" name="email" id="field-email" class="textfield placeholder-label block-auto required" placeholder="Email address?">
        <input type="text" name="school" id="field-school" class="textfield placeholder-label block-auto required" placeholder="School">
        <input type="text" name="graduation" id="field-graduation" class="textfield placeholder-label block-auto required" placeholder="Expected Graduation Month/Year">
        <input type="text" name="majors" id="field-majors" class="textfield placeholder-label block-auto required" placeholder="Major(s)">
        <input type="text" name="minors" id="field-minors" class="textfield placeholder-label block-auto" placeholder="Minors(s)">
        <input type="text" name="gpa" id="field-gpa" class="textfield placeholder-label block-auto required" placeholder="Current GPA">
        
        <textarea name="coursework" id="field-coursework" class="placeholder-label block-auto required" placeholder="Relevant Coursework"></textarea>
        
        <p class="form-sec-title">On a scale of 1-10 with 10 being the greatest, how would you rate your:</p>
        
        <label class="block-auto select-label" for="critical-thinking">Critical Thinking Skills</label>
        <select id="critical-thinking" name="critical_thinking_skills" class="block-auto required">
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
        </select>
        
        <label class="block-auto select-label" for="work-independently">Ability to Work Independently</label>
        <select id="work-independently" name="ability_to_work_independently" class="block-auto required">
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
        </select>
        
        <label class="block-auto select-label" for="work-partner">Ability to Work with a Partner on a Project</label>
        <select id="work-partner" name="ability_to_work_partner" class="block-auto required">
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
        </select>
        
        <label class="block-auto select-label" for="self-teach">Ability to Self-Teach</label>
        <select id="self-teach" name="ability_to_self_teach" class="block-auto required">
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
        </select>
        
        <label class="block-auto select-label" for="drupal-interest">Interest in Learning About the Drupal Platform</label>
        <select id="drupal-interest" name="interest_in_drupal" class="block-auto required">
          <option value="1">1</option>
          <option value="2">2</option>
          <option value="3">3</option>
          <option value="4">4</option>
          <option value="5">5</option>
          <option value="6">6</option>
          <option value="7">7</option>
          <option value="8">8</option>
          <option value="9">9</option>
          <option value="10">10</option>
        </select>
        
        <textarea name="interest_in_drupal_why" id="field-drupal-interest-why" class="placeholder-label block-auto required sub-question" placeholder="Why?"></textarea>
        
        <p class="form-sec-title">Please answer the following questions:</p>
        
        <input type="text" name="favorite_movie" id="field-movie" class="textfield placeholder-label block-auto required" placeholder="What is your favorite movie?">
        
        <textarea name="favorite_movie_why" id="field-movie-why" class="placeholder-label block-auto required sub-question" placeholder="Why?"></textarea>
        
        <label class="radios-overview block-auto">Do you like dogs?</label>
        <div class="radios-wrapper like-dogs">
          <div class="radio-wrapper">
            <input type="radio" value="yes" name="do_you_like_dogs" id="field-dogs-y"><label for="field-dogs-y">Yes</label>
          </div>
          <div class="radio-wrapper">
            <input type="radio" value="no" name="do_you_like_dogs" id="field-dogs-n"><label for="field-dogs-n">No</label>
          </div>
        </div>
        
        <textarea name="like_dogs_why" id="field-dogs-why" class="placeholder-label block-auto required sub-question" placeholder="Why?"></textarea>
        
        <label class="radios-overview block-auto">Do you have afternoon availability on 2-3 weekdays?</label>
        <div class="radios-wrapper afternoon-availability">
          <div class="radio-wrapper">
            <input type="radio" value="yes" name="afternoon_availability" id="field-avail-y"><label for="field-avail-y">Yes</label>
          </div>
          <div class="radio-wrapper">
            <input type="radio" value="no" name="afternoon_availability" id="field-avail-n"><label for="field-avail-n">No</label>
          </div>
        </div>
        
        <label class="radios-overview block-auto">Are you comfortable working in a home office environment?</label>
        <div class="radios-wrapper home-office">
          <div class="radio-wrapper">
            <input type="radio" value="yes" name="home_office" id="field-ho-y"><label for="field-ho-y">Yes</label>
          </div>
          <div class="radio-wrapper">
            <input type="radio" value="no" name="home_office" id="field-ho-n"><label for="field-ho-n">No</label>
          </div>
        </div>
        
        <textarea name="reason" id="field-reason" class="placeholder-label block-auto required" placeholder="Why are you interested in this internship?"></textarea>
        
        <label for="field-resume" class="block-auto file-label">R&eacute;sum&eacute;:</label>
        <input type="file" name="file-resume" id="field-resume" class="block-auto required">
        
        <a id="field-submit" class="block-auto no-scroll form-submit" href="#intern-form" tabindex="12" data-messages="#intern-form .form-messages">apply</a>
      </form> <!-- /#contact-form -->
    </section> <!-- /#portfolio-container /.container -->
    
    <!-- JS files -->
    <!--[if lt IE 9]>
      <script type="text/javascript" src="/scripts/js/vendor/html5shiv.js"></script>
    <![endif]-->
    <script type="text/javascript" src="/scripts/js/vendor/jquery-1.11.0.min.js"></script>
    <!--[if lte IE 9]>
      <script type="text/javascript" src="/scripts/js/lte-ie-9.js"></script>
    <![endif]-->
    <script type="text/javascript" src="/scripts/js/common-functions.js"></script>
    <script type="text/javascript" src="/scripts/js/jquery.ddxmlslider.js"></script>
    <script type="text/javascript" src="/scripts/js/main.js"></script>
  </body>
</html>