#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    long long n = opt<long long>("n");
    long long s = opt<long long>("s");
    long long max_b = opt<long long>("max_b");
    bool weight = opt<bool>("weight");
    
    cout << n << " " << s << "\n";
    
    for (int i = 0; i < n; i++) {
        long long a, b;
        b = rnd.next(1ll, max_b);
        a = rnd.next(0ll, b);
        if (weight) {
            if (rnd.next(0, 100) > 10) {
                a = rnd.next(b * 9ll / 10ll, b);
            } else {
                a = rnd.next(0ll, b / 10ll);
            }
        }
        cout << a << " " << b << "\n";
    }
    
    return 0;
}