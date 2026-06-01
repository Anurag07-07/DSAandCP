#include <bits/stdc++.h>
using namespace std;

bool targetSum(vector<int> nums,int start,int target) {
    if (target==0) {
        return true;
    }

    if (start == nums.size() && target != 0) {
        return false;
    }

    return targetSum(nums,start+1,target) || targetSum(nums,start+1,target-nums[start]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for(auto &x:nums)cin>>x;
        int target;cin>>target;
        cout<<targetSum(nums,0,target);
    }

    return 0;
}