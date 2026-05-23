//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    char c;cin>>c;
    int n;cin>>n;
    vector<int> nums(n,0);
    for (auto &i:nums) cin>>i;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 1; j <= nums[i]; ++j) {
            cout<<c;
        }
        cout<<endl;
    }
}
