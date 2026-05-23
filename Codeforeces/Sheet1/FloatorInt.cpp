//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    cout<<fixed<<setprecision(3);
    float n;cin>>n;
    int int_value = n;
    float float_value = n-int_value;
    if (float_value) {
        cout<<"float "<<int_value<<" "<<float_value;
    }else {
        cout<<"int "<<int_value<<endl;
    }
}
