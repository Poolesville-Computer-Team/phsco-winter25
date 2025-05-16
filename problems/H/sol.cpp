#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define io_optimize() ios::sync_with_stdio(0); cin.tie(0);
#define io_file(input_file, output_file) freopen(input_file, "r", stdin); freopen(output_file, "w", stdout);

int main() {
    io_optimize();
    // io_file("input.txt", "output.txt");

    // ----- WRITE CODE HERE ----- //
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int slen = s.length();

        int numzeros = 0;
        int numones = 0;
        for (char ch : s) {
            if (ch == '0') numzeros++;
            else numones++;
        }

        bool polly = false;
        if (b >= 2) {
            polly = (numones > 0);
        } else if (b == 1) {
            polly = (s[0] == '1' || s[slen-1] == '1');
        } else {
            polly = (numzeros == 0);
        }

        bool calvin = false;
        if (numones == 0) {
            calvin = true;
        } else if (numzeros == 0) {
            calvin = false;
        } else {
            // all partitions must contain at least 1 zero
            bool lastPartitionHasZero = false;
            for (int i = 0; i < slen - 1; i++) {
                char ch = s[i];
                if (ch == '0') {
                    if (b > 0) {
                        b -= 1;
                    } else if (!lastPartitionHasZero) {
                        lastPartitionHasZero = true;
                    }
                }
            }

            if (b == 0 & s[slen-1] == '0' && !lastPartitionHasZero) {
                lastPartitionHasZero = true;
            }

            calvin = (b == 0 && lastPartitionHasZero);
        }

        if (polly && calvin) cout << "TIE" << endl;
        else if (polly) cout << "POLLY" << endl;
        else cout << "CALVIN" << endl;
    }
}