public class Stack<T> {

    private T[] tab;
    private int topIndex;

    public Stack(int maxSize) {
        this.tab = (T[])new Object[maxSize];
        this.topIndex = -1;
    }

    public void push(int value) {
        if (this.topIndex == (this.tab.length - 1)) {
            System.out.println("error: stack is full!");
        } else {
            this.tab[++this.topIndex] = value;
        }
    }

    public int pop() {
        if (topIndex < 0) {
            throw new ArrayIndexOutOfBoundsException("error: stack is empty!");
        }
        return this.tab[this.topIndex--];
    }

    public boolean isEmpty() {
        return this.topIndex < 0;
    }

    public int top() {
        if (this.topIndex < 0) {
            System.out.println("error: stack is empty!");
            return -1;
        }

        return this.tab[this.topIndex];
    }
    
    public static void main(String[] args) {
        System.out.println("blblbl :-)");
    }
}