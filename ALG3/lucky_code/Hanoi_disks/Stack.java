import java.util.List;
import java.util.LinkedList;

public class Stack<T> {

    private List<T> list;

    public Stack() {
        this.list = new LinkedList<>();
    }

    public void push(T value) {
        this.list.add(value);
    }

    public T pop() {
        if (this.list.isEmpty()) {
            System.out.println("error: stack is empty!");
            return null;
        }
        return this.list.remove(this.list.size() - 1);
    }

    public T get(int index) {
        if ((this.list.size() - 1) < index) {
            //System.out.println("error: stack is empty!");
            return null;
        } else {
            return this.list.get(index);
        }
    }

    public boolean isEmpty() {
        return this.list.isEmpty();
    }

    public T top() {
        if (this.list.isEmpty()) {
            System.out.println("error: stack is empty!");
            return null;
        }

        return this.list.get(this.list.size() - 1);
    }
    
    public static void main(String[] args) {
        System.out.println("blblbl :-)");
    }
}