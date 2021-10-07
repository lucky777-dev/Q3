document.addEventListener("DOMContentLoaded",function() {
    const ageInput = document.getElementById("age")

    ageInput.addEventListener("blur", function(){
        if(isFinite(ageInput.value) && ageInput.value >=18){
            return true
        } else {
            alert("Age incorrect")
            return false
        }
    })
})
document.cookie
//nom=valeur;nom2=valeur2;
document.cookie.indexOf("nom")
document.cookie.substring
