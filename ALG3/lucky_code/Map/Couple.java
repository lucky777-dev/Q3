package Map;

// ON N'UTILISE PAS CETTE MÉTHODE
// Car on devrait chaque fois parcourir une liste
// Et cela mettrait beaucoup de temps avec beaucoup de clés

public class Couple<K, T> {

    private K key;
    private T value;

    public Couple(K key, T value) {
        this.key = key;
        this.value = value;
    }

    public T getValue(K key) {
        return this.value;
    }

    public K getKey(T value) {
        return this.key;
    }
}
