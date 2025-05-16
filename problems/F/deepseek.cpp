#include <vector>
#include <string>
#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int R_hidden = -1;
    for (int i = 0; i < n; ++i) {
        bool all_hash = true;
        for (char c : grid[i]) {
            if (c != '#') {
                all_hash = false;
                break;
            }
        }
        if (all_hash) {
            R_hidden = i;
            break;
        }
    }

    int C_hidden = -1;
    for (int c = 0; c < n; ++c) {
        bool all_hash = true;
        for (int r = 0; r < n; ++r) {
            if (grid[r][c] != '#') {
                all_hash = false;
                break;
            }
        }
        if (all_hash) {
            C_hidden = c;
            break;
        }
    }

    for (int r = 0; r < n; ++r) {
        if (r == R_hidden) continue;
        int count_x = 0, count_y = 0;
        for (int c = 0; c < n; ++c) {
            if (c == C_hidden) continue;
            if (grid[r][c] == 'X') count_x++;
            else if (grid[r][c] == 'Y') count_y++;
        }
        if (count_x + count_y == 2) {
            grid[r][C_hidden] = '.';
        } else {
            if (count_x == 1) {
                grid[r][C_hidden] = 'Y';
            } else if (count_y == 1) {
                grid[r][C_hidden] = 'X';
            }
        }
    }

    for (int c = 0; c < n; ++c) {
        if (c == C_hidden) {
            int count_x = 0, count_y = 0;
            for (int r = 0; r < n; ++r) {
                if (r == R_hidden) continue;
                if (grid[r][c] == 'X') count_x++;
                else if (grid[r][c] == 'Y') count_y++;
            }
            if (count_x == 0 && count_y == 1) {
                grid[R_hidden][c] = 'X';
            } else if (count_x == 1 && count_y == 0) {
                grid[R_hidden][c] = 'Y';
            }
        } else {
            int count_x = 0, count_y = 0;
            for (int r = 0; r < n; ++r) {
                if (r == R_hidden) continue;
                if (grid[r][c] == 'X') count_x++;
                else if (grid[r][c] == 'Y') count_y++;
            }
            if (count_x + count_y == 2) {
                grid[R_hidden][c] = '.';
            } else {
                if (count_x == 1) {
                    grid[R_hidden][c] = 'Y';
                } else if (count_y == 1) {
                    grid[R_hidden][c] = 'X';
                } else if (count_x == 0) {
                    grid[R_hidden][c] = 'X';
                } else if (count_y == 0) {
                    grid[R_hidden][c] = 'Y';
                }
            }
        }
    }

    for (const string& row : grid) {
        cout << row << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}