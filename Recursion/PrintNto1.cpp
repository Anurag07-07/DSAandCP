//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void Print(int n) {
    //Base Case
    //When n become equal 0 stop the calling
    if (n==0) {
        return;
    }

    //Print the value
    cout<<n<<" ";
    Print(n-2);
}

int main() {
    int n;cin>>n;
    Print(n);
}