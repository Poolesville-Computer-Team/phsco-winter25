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
        int n;
        cin >> n;

        vector<pair<int, int>> schedule(n);
        vector<bool> x(n);
        vector<bool> y(n);

        int xMissing = 0;
        int yMissing = 0;
        int col = -1;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            int xcd = s.find('X');
            int ycd = s.find('Y');

            if (xcd == -1) {
                xMissing++;
            } else {
                x[xcd] = true;
            }
            
            if (ycd == -1) {
                yMissing++;
            } else {
                y[ycd] = true;
            }

            if (col == -1 && !(xcd == -1 && ycd == -1)) {
                col = s.find('#');
            }

            schedule[i] = make_pair(xcd, ycd);
        }

        for (int i = 0; i < n; i++) {
            int xcd = schedule[i].first;
            int ycd = schedule[i].second;

            if (xcd == -1 && ycd == -1) {
                // The missing row
                if (xMissing == 1) {
                    xcd = col;
                } else {
                    for (int j = 0; j < n; j++) {
                        if (j != col && !x[j]) {
                            xcd = j;
                            break;
                        }
                    }
                }

                if (yMissing == 1) {
                    ycd = col;
                } else {
                    for (int j = 0; j < n; j++) {
                        if (j != col && !y[j]) {
                            ycd = j;
                            break;
                        }
                    }
                }
            } else if (xcd == -1) {
                // x must be placed here
                xcd = col;
            } else if (ycd == -1) {
                // y must be placed here
                ycd = col;
            }

            for (int j = 0; j < n; j++) {
                if (j == xcd) cout << "X";
                else if (j == ycd) cout << "Y";
                else cout << ".";
            }
            cout << endl;
        }
    }
}