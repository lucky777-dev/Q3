document.addEventListener("DOMContentLoaded", function() {
    let firstForm= document.getElementsByTagName("form")[0]
    console.log(firstForm)
    //alert("Le premier formulaire s'appelle " + firstForm.name)

    document.getElementsByName("Nom")[0].addEventListener("blur", function() {
        validateIsEmpty(this)
    })

    document.getElementsByName("Matricule")[0].addEventListener("blur", function() {
        validateNumberBetweenBounds(this, 10000, 99999)
    })
})

