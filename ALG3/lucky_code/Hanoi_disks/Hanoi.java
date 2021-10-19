public class Hanoi {

    //   Tiny = 0
    //  Small = 1
    // Medium = 2
    //  Large = 3

    private Stack<Integer> stack_A, stack_B, stack_C;

    public static void main(String[] args) {
        Hanoi h = new Hanoi();
        h.show();
        h.solve();
    }

    public Hanoi() {
        this.stack_A = new Stack<>();
        this.stack_B = new Stack<>();
        this.stack_C = new Stack<>();

        this.stack_A.push(3);
        this.stack_A.push(2);
        this.stack_A.push(1);
        this.stack_A.push(0);
    }

    public int solve(int n, Stack start, Stack inter, Stack end) {
        int cpt = 0;
        cpt += solve(n-1, start, end, inter);
        cpt += solve(n-1, inter, start, end);
        show();
        return cpt;
    }

    private void show() {
        String[] tab = {"   X   ", "  XXX  ", " XXXXX ", "XXXXXXX"};
        System.out.println();
        for (int i = 3; i >= 0; i--) {
            System.out.print("       ");
            System.out.print((this.stack_A.get(i) != null) ? tab[this.stack_A.get(i)] : "   |   ");
            System.out.print("       ");
            System.out.print((this.stack_B.get(i) != null) ? tab[this.stack_A.get(i)] : "   |   ");
            System.out.print("       ");
            System.out.println((this.stack_C.get(i) != null) ? tab[this.stack_A.get(i)] : "   |   ");
        }
        System.out.println("     -----------   -----------   -----------\n");
    }

    /*
    void hanoi(int n, char dep, char inter, char arriv) {
        if (n>0) {
            hanoi(n-1, dep, arriv, inter);
            sout("deplace le disque " + n + " depuis " + dep + " vers la pile " + arriv);
            hanoi(n-1, inter, dep, arriv);
        }
    }
    */
}