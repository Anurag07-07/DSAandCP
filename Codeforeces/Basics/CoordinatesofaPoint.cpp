//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    float X,Y;cin>>X>>Y;
    if (X>0 && Y>0) {
        cout<<"Q1";
    } else if (X<0 && Y>0) {
        cout<<"Q2";
    } else if (Y<0 && X>0) {
        cout<<"Q4";
    }else if (Y<0 && X<0) {
        cout<<"Q3";
    }else if (X==0 && Y==0) {
        cout<<"Origem"<<endl;
    }else if (Y==0) {
        cout<<"Eixo X";
    }else if (X==0) {
        cout<<"Eixo Y";
    }
}
