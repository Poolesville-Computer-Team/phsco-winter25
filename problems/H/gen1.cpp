#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int max_slen = opt<int>("max_slen");
    
    int n = 0;
    
    for (int i = 1; i <= max_slen; i++) {
        for (int a = 0; a < i; a++) {
            n += pow(2, i);
        }
    }
    
    cout << n << endl;

    for (int i = 1; i <= max_slen; i++) {
        for (int a = 0; a < i; a++) {
            int b = i - 1 - a;
            for (int s = 0; s < pow(2, i); s++) {
                cout << a << " " << b << endl;
                for (int j = 0; j < i; j++) {
                    cout << ((s >> j) & 1);
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}