//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void PrintEven(int n) {
    //Base Case
    //When n become negative
    if (n<0) {
        return;
    }

    //First We Call the Function and Reach till the -1
    //And from there we start printing the value
    PrintEven(n-2);
    cout<<n<<" ";
}

int main(int argc, char *argv[]) {
    int n;cin>>n;
    PrintEven(n);
}
