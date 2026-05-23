//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char *argv[]) {
    int a,b,c;cin>>a>>b>>c;
    int x = a;
    int y = b;
    int z = c;
    if (a>b) {
        swap(a,b);
        if (b>c) {
            swap(b,c);
            if (a>b) {
                swap(a,b);
            }
        }
    }else {
        if (b>c) {
            swap(b,c);
            if (a>b) {
                swap(a,b);
            }
        }
    }

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<z<<endl;
}
