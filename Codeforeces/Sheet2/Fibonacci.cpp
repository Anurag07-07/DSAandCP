//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
void fib(int n) {
    if (n<=1) {
        cout<<n<<" ";
        return;
    }
    fib(n-1);
    fib(n-2);
    cout<<n<<" ";
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    vector<int> fib(n,0);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n-1; ++i) {
        fib[i] = fib[i-1]+fib[i-2];
    }

    for (int i = 0; i < n; ++i) {
        cout<<fib[i]<<" ";
    }
}

