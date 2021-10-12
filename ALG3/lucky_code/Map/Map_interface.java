package Map;
import java.util.List;

interface Map_interface<K, T>{
    public void setElement(K key, T value);
    public T getValue(K key);
    public void delete(K key);
    public boolean contain(K key);
    public int size();
    public List<K> listKey();
}