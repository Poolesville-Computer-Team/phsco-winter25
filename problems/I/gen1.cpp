#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int t = opt<int>("t");
    int max_n = opt<int>("max_n");
    int max_a = opt<int>("max_a");
    int q = opt<int>("q");
    
    cout << t << "\n";
    
    for (int test = 0; test < t; test++) {
        int n = rnd.next(1, max_n);
        cout << n << " " << q << "\n";
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a = rnd.next(1, max_a);
            sum += a;
            cout << a;
            if (i != n - 1) cout << " ";
        }
        cout << "\n";
        for (int i = 0; i < q; i++) {
            int s = rnd.next(1, 1'000'000'000);
            cout << s << "\n";
        }
    }
    
    return 0;
}