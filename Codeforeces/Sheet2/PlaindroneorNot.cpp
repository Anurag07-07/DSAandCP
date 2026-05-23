//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    int value = n;
    //Find the Reverse of Number
    int ans = 0;
    while (n!=0) {
        int last = n%10;
        ans = ans*10+last;
        n = n/10;
    }
    if (ans==value) {
        cout<<ans<<endl;
        cout<<"YES"<<endl;
    }else {
        cout<<ans<<endl;
        cout<<"NO"<<endl;
    }
}
