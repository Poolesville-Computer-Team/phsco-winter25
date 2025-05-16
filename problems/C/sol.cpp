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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int res = 2;
        if (a == c) res--;
        if (b == d) res--;
        cout << res << endl;
    }
}