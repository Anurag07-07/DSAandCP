//
// Created by anura on 09-05-2026.
//



#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b) {
   //Base case
    if (a==0) {
        return b;
    }
    return GCD(a%b,a);
}
int main(int argc, char *argv[]) {
    int a,b;cin>>a>>b;
    cout<<GCD(a,b);
}


