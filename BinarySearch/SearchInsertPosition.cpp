//
// Created by anura on 27-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;int end = n-1;
        int ans = n;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid]>target) {
                ans = mid;
                end = mid - 1;
            }else {
                start = mid+1;
            }
        }
        return ans;
    }
};

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
        cout<<s.searchInsert(nums,target);

    }
}
