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

    int pollyattacks = 0;
    int pollysuper = 0;
    while (c > 0) {
        pollysuper += 1;
        if (pollysuper == 3) {
            c -= b;
            pollysuper = 0;
        }
        c -= b;
        pollyattacks += 1;
    }

    int calvinattacks = 0;
    int calvinsuper = 0;
    while (a > 0) {
        calvinsuper += 1;
        if (calvinsuper == 3) {
            a -= d;
            calvinsuper = 0;
        }
        a -= d;
        calvinattacks += 1;
    }

    if (pollyattacks > calvinattacks) cout << -1 << endl;
    else cout << (calvinattacks-pollyattacks) << endl;
}