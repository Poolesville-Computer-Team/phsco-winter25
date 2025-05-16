#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define io_optimize() ios::sync_with_stdio(0); cin.tie(0);
#define io_file(input_file, output_file) freopen(input_file, "r", stdin); freopen(output_file, "w", stdout);

int main() {
    io_optimize();
    // io_file("input.txt", "output.txt");

    // ----- WRITE CODE HERE ----- //
    ll n, s;
    cin >> n >> s;


    ll pts = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        pts += a;
        tot += b;
    }

    pts += s;
    tot += s;

    if (pts * 10 >= tot * 9) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}