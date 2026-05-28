//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int getith(int n,int i) {
    int mask = 1<<i;
    int ans = n&mask;
    return ans > 0 ? 1 : 0;
}

int setbit(int n ,int pos) {
    int mask = 1<<pos;
    int ans = n | mask;
    return ans;
}

int updatebit(int n,int i,int v) {
    //Clear the Bit
    int mask = ~(1<<i);
    n = mask&n;

    //Update the Bit
    int mask2 = v<<i;
    n = n | mask2;

    return n;
}

int clearlastithBits(int n,int i) {
    return n & (-1<<i+1);
}

int clearbit(int n,int i) {
    int mask = ~(1<<i);
    int ans = n & mask;
    return  ans;
}
//     i      j
// 1111001010101010
// 1111000000001010
// 1111000000000000
// 0000000000001111


int clearbitinrange(int n,int i,int j) {
    int mask1 = -1<<(i+1);
    int mask2 = (1<<j)-1;
    int mask3 = mask1 | mask2;
    int ans = n & mask3;
    return ans;
}

//     i    j
// 11110010101010
// 11110000000000
// 00000000001111
// 11110000001010

int main() {
    int n,i;cin>>n>>i;
    int j;cin>>j;

    // int v;cin>>v;
    // cout<<getith(n,i)<<endl;
    // cout<<setbit(n,i)<<endl;
    // cout<<clearbit(n,i)<<endl;
    // cout<<updatebit(n,i,v)<<endl;

    // cout<<clearlastithBits(n,i);
    // cout<<clearlastithBits(n,i);
       cout<<clearbitinrange(n,i,j);
}
