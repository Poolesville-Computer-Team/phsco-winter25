#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void shuffle(vector<int>& vec) {
    int n = vec.size();
    for (int i = n - 1; i > 0; i--) {
        int j = rnd.next(0, i);
        swap(vec[i], vec[j]);
    }
}

vector<int> derangement(int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    
    while (true) {
        shuffle(perm);
        
        bool is_derangement = true;
        for (int i = 0; i < n; i++) {
            if (perm[i] == i) {
                is_derangement = false;
                break;
            }
        }
        
        if (is_derangement) return perm;
    }
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int t = opt<int>("t");
    int n = opt<int>("n");
    
    cout << t << "\n";
    
    for (int i = 1; i <= t; i++) {
        vector<int> x(n);
        vector<int> y(n);
        for (int j = 0; j < n; j++) {
            x[j] = j;
            y[j] = j;
        }

        shuffle(x);
        vector<int> yIntermed = derangement(n);
        for (int i = 0; i < n; i++) {
            y[i] = x[yIntermed[i]];
        }

        int row = rnd.next(0, n-1);
        int col = rnd.next(0, n-1);
        cout << n << "\n";
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (r == row || c == col) cout << "#";
                else if (c == x[r]) cout << "X";
                else if (c == y[r]) cout << "Y";
                else cout << ".";
            }
            cout << "\n";
        }
    }
    
    return 0;
}