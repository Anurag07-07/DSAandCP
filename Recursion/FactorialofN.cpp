//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    //Base case
    //Factorial of 0 is 1
    if (n==0) {
        return 1;
    }

    //Factorial of 5 is 5*factorial of 4
    //Factorial of 4 is 4*factorial of 3
    //Factorial of n is n*factorial of n-1
    return n*factorial(n-1);
}

int main(int argc, char *argv[]) {
    int n;cin>>n;
    cout<<factorial(n);
}
