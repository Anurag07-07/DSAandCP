# include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while (start<end) {
            int mid = start+(end-start)/2;

            if (nums[mid]==nums[end]) {
                end--;
            }

            else if (nums[mid]<nums[end]) {
                end  = mid;
            }

            else {
                start = mid+1;
            }

        }
        return nums[start];
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
        cout<<s.findMin(nums);
    }

    return 0;
}