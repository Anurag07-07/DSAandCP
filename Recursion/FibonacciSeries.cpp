//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n) {
    //Base Case
    //First Fibonacci is 0
    //Second Fibonacci is 1
    if (n==0 || n==1) {
        return n;
    }

    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(int argc, char *argv[]) {
    int n;cin>>n;
    cout<<Fibonacci(n);
}

