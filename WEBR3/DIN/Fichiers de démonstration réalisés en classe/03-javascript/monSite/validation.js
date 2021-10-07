function validateIsEmpty(champ) {
    if (champ.value.length == 0) {
        champ.nextSibling.innerText="Ce champ ne peut pas être vide"
        return false
    } else {
        champ.nextSibling.innerText=""
        return true
    }
}

function validateNumberBetweenBounds(champ, lowerBound, upperBound) {
    if (isFinite(champ.value) && champ.value >= lowerBound && champ.value <= upperBound) {
        champ.nextSibling.innerText=""
        return true
    } else {
        champ.nextSibling.innerText="Ce champ doit contenir un nombre entre " + lowerBound + " et " + upperBound
        return false
    }
}