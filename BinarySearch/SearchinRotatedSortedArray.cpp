# include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (nums[mid]==target) {
                return true;
            }

            if (nums[start]==nums[mid] && nums[end]==nums[mid]) {
                start++;
                end--;
            }
            else if (nums[mid]>=nums[start]) {
                if (nums[mid]>target && nums[start]<=target) {
                    end = mid-1;
                }else {
                    start = mid+1;
                }
            }else {
                if (nums[mid]<target && nums[end]>=target) {
                    start = mid+1;
                }else {
                    end = mid-1;
                }
            }
        }
        return false;
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
        cout<<s.search(nums,target);
    }

    return 0;
}