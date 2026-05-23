//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
void PrintTable(int start,int end) {
    if (start>12) {
        return;
    }
    cout<<end<<" * "<<start<<" = " <<end*start<<endl;
    PrintTable(start+1,end);
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    PrintTable(1,n);
}

