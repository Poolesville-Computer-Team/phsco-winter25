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
        for (int i = 0; i < n; i++) {
            ll d;
            cin >> d;
            dice.push_back(d);
        }

        sort(dice.begin(), dice.end(), greater<ll>());

        vector<ll> sums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += dice[i];
            sums[i] = sum;
        }

        for (int i = 0; i < q; i++) {
            ll s;
            cin >> s;
            
            ll rolled = 0;
            ll minturns = 0;

            minturns = ((s + sum - 1) / sum);

            ll lo = 0;
            ll hi = n;

            while (lo < hi) {
                ll mid = lo + (hi - lo) / 2;
                if (minturns * sums[mid] >= s) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            if (lo > 0) {
                s -= minturns * sums[lo - 1];
                rolled += minturns * lo;
            }

            if (s > 0) {
                ll toroll = dice[lo];
                rolled += (s + toroll - 1) / toroll;
            }

            cout << minturns << " " << rolled << endl;
        }
    }
}