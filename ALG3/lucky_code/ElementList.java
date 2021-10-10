public class ElementList<T> {

    private T value;
    private ElementList<T> next;

    public ElementList(T value) {
        this(value, null);
    }

    public ElementList(T value, ElementList<T> elementList) {
        this.value = value;
        this.next = elementList;
    }

    public T getValue() {
        return this.value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public ElementList<T> getNext() {
        return this.next;
    }

    public void setNext(ElementList<T> element) {
        this.next = element;
    }
}
