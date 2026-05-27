//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for (auto &i:nums) {
            cin>>i;
        }

        int count = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            count  =  count &nums[i];
        }
        cout<<count<<endl;
    }
}
