$(document).ready(function() {
    $(".PresentationPhotos ul li").hide();
    $(".PresentationPhotos ul li:first").fadeIn();
    $(".PresentationPhotos ul li").click(function() {
        $(this).fadeOut(function() {
                                if ($(this).is(":last-child")) {
                                    $(this).siblings().first().fadeIn();
                                } else {
                                    $(this).next().fadeIn();
                                }
                            });
    })
})