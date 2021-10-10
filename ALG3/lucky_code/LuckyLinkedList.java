public class LuckyLinkedList<T> {
    
    private ElementList<T> first;

    public LuckyLinkedList() {
        this.first = null;
    }

    public ElementList<T> getFirst() {
        return this.first;
    }

    public void setFirst(ElementList<T> element) {
        this.first = element;
    }

    public boolean isEmpty() {
        return this.first == null;
    }

    public void insertHead(T value) {
        this.first = new ElementList<T>(value, this.first);
    }

    public void deleteHead() {
        if (this.first != null) {
            this.first = this.first.getNext();
        }
    }

    public void insertAfter(ElementList<T> element, T value) {
        if (element == null) {
            System.out.println("error: given element is null");
        } else {
            element.setNext(new ElementList<T>(value, element.getNext()));
        }
    }

    public void deleteAfter(ElementList<T> element) {
        if (element.getNext() != null) {
            element.setNext(element.getNext().getNext());
        } else {
            System.out.println("error: LuckyLinkedList is empty!");
        }
    }
}