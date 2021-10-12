package Map;
import java.util.List;
import java.util.LinkedList;

public class Map<K, T> {

    private List<K> key;
    private List<T> value;

    public Map(K key, T value) {
        this.key = new LinkedList<>();
        this.value = new LinkedList<>();
    }

    public void setElement(K key, T value) {

    }

    public T getValue(K key) {     // Erreur si clé non présente
        return null;
    }

    public void delete(K key) {

    }

    public boolean contain(K key) {
        return false;
    }

    public int size() {   // Nombre de clés
        return 0;
    }

    public List<K> listKeys() {
        return null;
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}