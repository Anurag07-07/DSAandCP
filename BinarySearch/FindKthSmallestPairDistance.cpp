#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePairBrute(vector<int>& nums, int k)
    {
        vector<int> diff;
        for (int i = 0; i < nums.size()-1; ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                diff.push_back(abs(nums[j]-nums[i]));
            }
        }

        sort(diff.begin(),diff.end());
        return diff[k-1];
    }

    bool isPossible(vector<int> nums,int mid,int k) {
        int i = 0;
        int count = 0;
        for (int j = 0; j < nums.size(); ++j) {
            while (nums[j]-nums[i]>mid) {
                i++;
            }
            count += (j-i);
        }
        return count>=k;
    }
    int smallestDistancePairOptimal(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums[n-1];
        int ans = end;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (isPossible(nums,mid,k)) {
                ans = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return ans;
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
        int k;cin>>k;
        cout<<s.smallestDistancePairOptimal(nums,k);
    }

    return 0;
}