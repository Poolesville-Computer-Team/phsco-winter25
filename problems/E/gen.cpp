#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int n = opt<int>("n");
    int len = opt<int>("len");
    
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            int rnum = rnd.next(0, 15);
            if (rnum < 10) {
                cout << (char)('0' + rnum);
            } else {
                cout << (char)('A' + (rnum - 10));
            }
        }
        cout << endl;
    }
    
    return 0;
}