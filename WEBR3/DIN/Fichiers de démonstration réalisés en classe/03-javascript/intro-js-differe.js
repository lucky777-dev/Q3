document.addEventListener("DOMContentLoaded",function() {
    let paragraphs= document.getElementsByTagName("p")
    for (let i=0;i<paragraphs.length;i++) {
        let p = paragraphs[i]
        p.style = "color:red;"
        let button = document.createElement("button")
        button.innerText ="Bouton "+i
        p.appendChild(button)
        button.addEventListener("click", function(){
            alert("Bouton " + i +" cliqué")
        })
    }
})



