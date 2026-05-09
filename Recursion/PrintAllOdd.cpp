//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

void PrintAllOdd(int n) {
    //Base Case
    if (n<1) {
        return;
    }

    //Function Calling
    if (n%2==0) {
        PrintAllOdd(n-1);
    }else {
        PrintAllOdd(n-2);
    }

    //Print the Value
    if (n%2==1)cout<<n<<" ";
}

void AnotherWay(int x,int n) {
    //Base Case
    if (x>n) {
        return;
    }

    cout<<x<<" ";
    AnotherWay(x+2,n);
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    PrintAllOdd(n);
    cout<<endl;
    AnotherWay(1,n);
}
