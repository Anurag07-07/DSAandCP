//
// Created by anura on 27-05-2026.
//
# include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = n;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (arr[mid]-(mid+1)>=k) {
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return ans+k;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    Solution s;

    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for(auto &x:nums)cin>>x;
        int target;cin>>target;
        cout<<s.findKthPositive(nums,target);
    }

    return 0;
}