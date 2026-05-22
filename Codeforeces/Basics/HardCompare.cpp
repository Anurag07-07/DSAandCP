//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    long long a,b,c,d;cin>>a>>b>>c>>d;
    if (b*log(a)>d*log(c)) {
        cout<<"YES";
    }else {
        cout<<"NO";
    }
}
