#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> nums,int mid,int h) {
        long long hrs = 0;
        for (int x:nums) {
            hrs+= ((x+(mid-1))/mid);
            if (hrs>h) {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());

        int ans = start;

        while (start<=end) {
            int mid = start+(end-start)/2;
            if (isPossible(piles,mid,h)) {
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

    int t;
    cin >> t;

    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (auto &x: nums)cin >> x;
        int h;cin>>h;
        cout<<s.minEatingSpeed(nums,h);
    }

    return 0;
}
