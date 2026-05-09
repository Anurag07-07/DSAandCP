//
// Created by anura on 09-05-2026.
//

#include<bits/stdc++.h>
using namespace std;



void Print(int x,int n) {
    //Base Case
    //When x is equal to n

    if (x>n) {
        return;
    }

    //Print the Number
    cout<<x<<" ";

    //Call the Function with increment of 1
    Print(x+1,n);
}

int main(int argc, char *argv[]) {
    int n;cin>>n;
    Print(1,n);
}

