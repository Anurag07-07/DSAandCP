//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i < n; ++i) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            cout<<i<<" ";
        }
    }
    return 0;
}
