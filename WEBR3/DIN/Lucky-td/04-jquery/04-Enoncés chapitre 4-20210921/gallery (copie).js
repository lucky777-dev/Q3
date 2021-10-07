//Solution de l'enseignant

$(document).ready(function() {
    $(".PresentationPhotos ul li").click(function() {
        $(this).hide();
        if ($(this).is(":last-child")) {
            $(this).siblings().first().show();
        } else {
            $(this).next().show();
        }
    });
})