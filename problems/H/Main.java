import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t;
        t = sc.nextInt(); 

        for (int test = 0; test < t; test++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            String s;
            s = sc.next();

            int slen = s.length();
            int numzeros = 0;
            int numones = 0;

            for (int i = 0; i < slen; i++) {
                char ch = s.charAt(i);
                if (ch == '0') numzeros++;
                else numones++;
            }

            boolean polly = false;
            if (b >= 2) {
                polly = (numones > 0);
            } else if (b == 1) {
                polly = (s.charAt(0) == '1' || s.charAt(slen-1) == '1');
            } else {
                polly = (numzeros == 0);
            }

            boolean calvin = false;
            if (numones == 0) {
                calvin = true;
            } else if (numzeros == 0) {
                calvin = false;
            } else {
                // all partitions must contain at least 1 zero
                boolean lastPartitionHasZero = false;
                for (int i = 0; i < slen - 1; i++) {
                    char ch = s.charAt(i);
                    if (ch == '0') {
                        if (b > 0) {
                            b -= 1;
                        } else if (!lastPartitionHasZero) {
                            lastPartitionHasZero = true;
                        }
                    }
                }

                if (b == 0 & s.charAt(slen-1) == '0' && !lastPartitionHasZero) {
                    lastPartitionHasZero = true;
                }

                calvin = (b == 0 && lastPartitionHasZero);
            }

            if (polly && calvin) System.out.println("TIE");
            else if (polly) System.out.println("POLLY");
            else System.out.println("CALVIN");
        }
    }
}