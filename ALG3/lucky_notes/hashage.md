# ALG3

# Hashage
> Transformation d'une information en un entier unique.

## Table de hashage

> On effectue un hashage sur chaque élément et on écrit leur valeur respective à l'adresse correspondant au hash.

## Map<K, T> avec hashage **`h`**

1. On utilise une classe:
```java
Element<K, T> {
    K clef;
    T valeur;
}
```
2. Créer un tableau dont les entrées sont `Element<K, T>`
3. Si on veut stocker une instance **`d`** de `ElementList<K, T>`, je le place en position `h(d.clef)` du tableau.

### Exemple:

> Prenons `(33, "Arthur")`<br>
On le place en position `h(33)` en utilisant la fonction de hashage `h(c) = c % 10`<br>
On le place donc en position `3`.<br>