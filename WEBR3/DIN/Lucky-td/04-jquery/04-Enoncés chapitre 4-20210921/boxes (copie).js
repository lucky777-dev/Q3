//Solution du prof...

function select() {
    $(this).clone().appendTo("#Sel").click(unSelect)
    $(this).remove()
}

function unSelect() {
    $(this).clone().appendTo("#nonSel").click(select);
    $(this).remove()
}

$(document).ready(function() {
    $("#nonSel .unItem").click(select)
    $("#Sel .unItem").click(unSelect)
});