import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read n and s
        long n = sc.nextLong();
        long s = sc.nextLong();

        long pts = 0;
        long tot = 0;

        // Read n pairs of a and b
        for (int i = 0; i < n; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            pts += a;
            tot += b;
        }

        // Add s to pts and tot
        pts += s;
        tot += s;

        // Perform the check and output the result
        if (pts * 10 >= tot * 9) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        sc.close();
    }
}
