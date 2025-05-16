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
            
            ll rolled = 0;
            ll minturns = 0;
            
            minturns = ((s + sum - 1) / sum);

            for (int die = 0; die < n; die++) {
                ll toroll = dice[die];
                if (s > minturns * toroll) {
                    rolled += minturns;
                    s -= toroll * minturns;
                } else {
                    rolled += (s + toroll - 1) / toroll;
                    s = 0;
                }
                if (s <= 0) break;
            }

            cout << minturns << " " << rolled << endl;
        }
    }
}