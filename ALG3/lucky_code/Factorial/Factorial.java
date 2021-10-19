public class Factorial {
    public static void main(String[] args) {
        System.out.println("Factorial of 4:");
        System.out.println("4! = " + fact(4));
    }

    public static int fact(int n) {

        if (n==0) {
            System.out.print("1\n");
            return 1;
        }
        System.out.print(n + " * ");
        return n*fact(n-1);
    }
}