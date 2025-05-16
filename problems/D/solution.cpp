#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define io_optimize() ios::sync_with_stdio(0); cin.tie(0);
#define io_file(input_file, output_file) freopen(input_file, "r", stdin); freopen(output_file, "w", stdout);

int main() {
    io_optimize();
    // io_file("input.txt", "output.txt");

    // ----- WRITE CODE HERE ----- //
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int misses = 0;
    int pollysuper = 0;
    int calvinsuper = 0;
    while (a > 0 && c > 0) {
        int pollydmg = b;
        if (pollysuper == 2) pollydmg *= 2;

        int calvindmg = d;
        calvinsuper += 1;
        if (calvinsuper == 3) {
            calvinsuper = 0;
            calvindmg *= 2;
        }

        // If Polly's damage won't defeat Calvin, Polly lands a hit
        if (c - pollydmg > 0) {
            c -= pollydmg;
            pollysuper += 1;
            pollysuper %= 3;
        } else {
            // Polly can defeat Calvin on her next attack
            // Check if Polly will survive Calvin's attack

            if (a - calvindmg > 0) {
                // Polly lives
                misses += 1;
            } else {
                // Polly must attack
                // (this will defeat Calvin, so we can immediately exit the loop)
                break;
            }
        }

        a -= calvindmg;
    }

    if (a <= 0) cout << -1 << endl;
    else cout << misses << endl;
}