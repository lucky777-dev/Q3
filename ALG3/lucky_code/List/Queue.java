import java.util.List;
import java.util.LinkedList;

public class Queue<T> {

    private List<T> list;

    public Queue() {
        this.list = new LinkedList<>();
    }

    public void enqueue(T value) {
        this.list.add(value);
    }

    public T dequeue() {
        if (this.isEmpty()) {
            System.out.println("error: queue is empty!");
            return null;
        }
        return this.list.remove(0);
    }

    public T head() {
            if (this.isEmpty()) {
                System.out.println("error: queue is empty!");
                return null;
            }
            return this.list.get(0);
    }

    public boolean isEmpty() {
        return this.list.isEmpty();
        //return this.list.size() == 0;       Good too
    }

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}