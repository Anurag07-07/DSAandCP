//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int DigitSum(int n) {
    int value = 0;
    while (n!=0) {
        value += n%10;
        n = n/10;
    }
    return value;
}
int main(int argc, char *argv[]) {
    int n,a,b;cin>>n>>a>>b;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int value = DigitSum(i);
        if (value>=a && value<=b) {
            sum += i;
        }
    }
    cout<<sum<<endl;
}
