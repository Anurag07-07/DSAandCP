//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    if (n==1) {
        cout<<-1<<endl;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (i%2==0) cout<<i<<endl;
    }
}
