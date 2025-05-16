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
        string s;
        cin >> s;
        int slen = s.length();

        map<char, ll> val_map;
        ll res = 0;
        ll max_val = 15;
        for (int i = 0; i < slen; i++) {
            char ch = s[i];
            ll place = slen - 1 - i;
            
            if (val_map.count(ch) == 0) {
                val_map[ch] = max_val--;
            }

            res += (ll)(pow(16, place)) * val_map[ch];
        }

        cout << res << "\n";
    }
}