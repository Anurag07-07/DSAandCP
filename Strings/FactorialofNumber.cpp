//
// Created by anura on 25-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    vector<int> ans(1,1);
    while (n>1) {
        int carry = 0;
        int sz = ans.size();
        for (int i = 0; i < sz; ++i) {
            int data = ans[i]*n+carry;
            carry = data/10;
            ans[i] = data%10;
        }

        //Store the Carry
        while (carry) {
            ans.push_back(carry%10);
            carry/=10;
        }
        n--;
    }

    reverse(ans.begin(),ans.end());
    for (int x:ans) {
        cout<<x<<" ";
    }
}
