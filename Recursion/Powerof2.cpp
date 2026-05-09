//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

int powerof2(int x,int n) {
    //Base Case
    //Anything power 0 is 1
    if (n==0) {
        return 1;
    }

    //2^5 = 2*2^4
    //2^4 = 2*2^3
    //2^3 = 2*2^2
    //2^n = 2*2^n-1

    return 2*powerof2(x,    n-1);

}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    cout<<powerof2(2,n);
}
