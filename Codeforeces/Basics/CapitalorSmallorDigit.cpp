//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    char c;cin>>c;
    if (c>='a' && c<='z') {
        cout<<"ALPHA"<<endl;
        cout<<"IS SMALL"<<endl;
    }else if (c>='A' && c<='Z') {
        cout<<"ALPHA"<<endl;
        cout<<"IS CAPITAL"<<endl;
    }else {
        cout<<"IS DIGIT"<<endl;
    }
}
