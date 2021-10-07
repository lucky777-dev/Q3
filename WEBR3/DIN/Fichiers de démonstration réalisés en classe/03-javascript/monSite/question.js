document.addEventListener("DOMContentLoaded", function() {
    let button = document.getElementById("boutonReponse")
    button.addEventListener("click", function() {
        button.style = "display:none;"
        //document.getElementById("Reponse").style="display:inherit;"
        let reponse = document.createElement("p")
        reponse.innerText = "Document Object Model"
        document.getElementsByTagName("main")[0].appendChild(reponse)
    })
})