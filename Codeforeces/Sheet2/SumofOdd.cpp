//
// Created by anura on 23-05-2026.
//
//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t--) {
        int a,b;cin>>a>>b;
        int start = a>=b ? b : a;
        int end = a>=b ? a : b;
        int sum = 0;
        for (int i = start+1; i < end; ++i) {
            if (i%2==1) {
                sum += i;
            }
        }
        cout<<sum<<endl;
    }
}
