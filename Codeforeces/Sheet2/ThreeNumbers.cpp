//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int k,s;cin>>k>>s;
    int count = 0;
    for (int x = 0; x <= k; ++x) {
        for (int y = 0; y <= k; ++y) {
            if ((s-(x+y))>=0 && (s-(x+y))<=k ) {
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
