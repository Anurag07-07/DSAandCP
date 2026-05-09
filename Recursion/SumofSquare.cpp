//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

int SumofSquare(int n) {
    //Base Case
    //sum of 1 is 1
    //Sum of 0 is 0
    if (n==0) {
        return 0;
    }

    //SumofSquare  of 5 = 5^2+SumofSquare(4)
    //SumofSquare  of 4 = 4^2+SumofSquare(3)
    //SumofSquare  of n = n^2+SumofSquare(n-1)

    return n*n+SumofSquare(n-1);
}

int main(int argc, char *argv[]) {
    int n;cin>>n;
    cout<<SumofSquare(n);
}
