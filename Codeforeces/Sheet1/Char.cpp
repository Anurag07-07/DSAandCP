//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    char c;cin>>c;
    if (c>='a' && c<='z') {
        cout<<(char)(c-32)<<endl;
    } else {
        cout<<(char)(c+32)<<endl;
    }
}
