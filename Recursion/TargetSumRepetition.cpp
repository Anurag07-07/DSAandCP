#include <bits/stdc++.h>
using namespace std;

int SumCalculation(vector<int> nums,int target,int start,int end) {
    if (target==0) {
        return 1;
    }

    if (start==end  || target<0) {
        return 0;
    }

    return SumCalculation(nums,target-nums[start],start,end)+SumCalculation(nums,target,start+1,end);
}

int TargetSumRepetition(vector<int> nums,int target) {
    return SumCalculation(nums,target,0,nums.size());
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (auto &x: nums)cin >> x;
        int target;cin>>target;
        cout<<TargetSumRepetition(nums,target);
    }

    return 0;
}
