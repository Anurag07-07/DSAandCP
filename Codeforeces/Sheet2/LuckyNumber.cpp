//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool isLucky(int n) {
    int other = 0;
    while (n!=0) {
        if (n%10!=4 && n%10!=7){
            other++;
        }
        n/=10;
    }
    return other!=0 ? false : true;
}
int main(int argc, char *argv[]) {
    int a,b;cin>>a>>b;
    int lucky = 0;
    for (int i = a; i <=b ; ++i) {
        if (isLucky(i)) {
            lucky++;
            cout<<i<<" ";
        }
    }

    if (lucky==0) {
        cout<<-1;
    }
    return 0;
}
