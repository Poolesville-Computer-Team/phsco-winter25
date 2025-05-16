#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int per = opt<int>("per");
    int maxlen = opt<int>("max-len");
    
    cout << (per * maxlen) << endl;

    for (int len = 1; len <= maxlen; len++) {
        for (int i = 0; i < per; i++) {
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
    }
    
    return 0;
}