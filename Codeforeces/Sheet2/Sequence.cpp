//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    while (true) {
        int n,m;cin>>n>>m;
        if (n<=0 || m<=0) {
            break;
        }

        int start = n>=m ? m : n;
        int end = n>=m ? n : m;

        int sum = 0;
        for (int i = start; i <=end ; ++i) {
            sum += i;
        }

        start = n>=m ? m : n;
        end = n>=m ? n : m;

        for (int i = start; i <= end; ++i) {
            cout<<i<<" ";
        }
        cout<<"sum"<<" "<<"="<<sum<<endl;
    }
}
