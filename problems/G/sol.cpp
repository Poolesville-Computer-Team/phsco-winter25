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
        ll n;
        cin >> n;

        ll xsquared = n / 2;
        ll x = (ll)sqrt(xsquared);

        if (n == 1) {
            // edge case
            cout << "0 5" << endl;
        } else if ((x * x) + (x + 1) * (x + 1) <= n) {
            // 12 sols exist
            cout << x << " " << 12 << endl;
        } else {
            // 4 sols exist
            cout << x << " " << 4 << endl;
        }
    }
}