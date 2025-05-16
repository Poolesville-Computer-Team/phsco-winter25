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
        ll n, q;
        cin >> n >> q;
        vector<ll> dice(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll d;
            cin >> d;
            dice.push_back(d);
            sum += d;
        }

        sort(dice.begin(), dice.end(), greater<ll>());

        for (int i = 0; i < q; i++) {
            ll s;
            cin >> s;
            
            ll orig_s = s;
            ll rolled = 0;
            ll minturns = 0;
            
            while (s >= sum) {
                s -= sum;
                minturns++;
            }

            if (s > 0) {
                minturns++;
            }

            s = orig_s;

            for (int die = 0; die < n; die++) {
                for (int amt = 0; amt < minturns; amt++) {
                    s -= dice[die];
                    rolled++;
                    if (s <= 0) break;
                }
                if (s <= 0) break;
            }

            cout << minturns << " " << rolled << endl;
        }
    }
}