//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    while (n--) {
        long long a;cin>>a;
        long long pro = 1;
        for (int i = 1; i <= a; ++i) {
            pro*=i;
        }
        cout<<pro<<endl;
    }
}
