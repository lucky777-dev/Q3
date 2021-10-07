//J'ai galeré pour cet exercice...

function nonSel(newItem) {
    $(newItem).click(function() {
        tmp = $(newItem).clone().appendTo("#Sel")
        $(newItem).remove();
        Sel(tmp)
    })
}

function Sel(newItem) {
    $(newItem).click(function() {
        tmp = $(newItem).clone().appendTo("#nonSel")
        $(newItem).remove();
        nonSel(tmp)
    })
}

$(document).ready(function() {
    $("#nonSel .unItem").click(function() {
        tmp = $(this).clone().appendTo("#Sel")
        $(this).remove();
        Sel(tmp)
    })

    $("#Sel .unItem").click(function() {
        tmp = $(this).clone().appendTo("#nonSel")
        $(this).remove();
        nonSel(tmp);
    })
});