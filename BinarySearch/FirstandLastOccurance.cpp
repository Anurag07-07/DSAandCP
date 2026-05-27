//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        vector<int> ans(2);
        int start = 0;int end = nums.size()-1;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (nums[mid]==target) {
                first = mid;
                end = mid-1;
            }else if (nums[mid]>target) {
                end = mid-1;
            }else {
                start = mid+1;
            }
        }

        start = 0;end = n-1;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (nums[mid]==target) {
                last = mid;
                start = mid+1;
            }else if (nums[mid]>target) {
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        vector<int> a;

        a.push_back(first);
        a.push_back(last);

        return a;
    }
};

// #include <bits/stdc++.h>
// using namespace std;

int main(int argc, char *argv[]) {
    int t;cin>>t;
    Solution s;
    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for (auto &i:nums) {
            cin>>i;
        }

        int target;cin>>target;
        vector<int> ans  = s.searchRange(nums,target);

        for (int x :ans) {
            cout<<x<<" ";
        }

    }
}
