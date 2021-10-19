public class Combinatory {
    public static void main(String[] args) {
        System.out.println("Combinatory with k=2 and n=4 is equal to:");
        System.out.println("C_2_4 = " + combi(2, 4));
    }

    public static int combi(int k, int n) {
        
        System.out.println("k=" + k + ", n=" + n);
        
        if(1<=k && k<n) {
            System.out.println("k=" + k + ", n=" + n);
            //System.out.println("(k=" + k + ", n=" + (n-1) + ") + (k=" + (k-1) + ", n=" + (n-1) + ")");
            return (combi(k, n-1) + combi(k-1, n-1));
        }
        else {
            return 1;
        }
    }
}