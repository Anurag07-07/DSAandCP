//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int sumofN(int n) {
    //Base case
    //Sum of 1 is 1
    if (n==1) {
        return 1;
    }

    //Sum of 5 is 5 + Sum of 4
    //Sum of 4 is 4 + Sum of 3
    //Sum of 3 is 3 + Sum of 2
    //Sum of n is n + Sum of n-1
    return n+sumofN(n-1);
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    cout<<sumofN(n);
}
