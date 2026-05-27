#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> stalls,int distance,int k) {
        int cows = 1;
        int stall = stalls[0];
        for (int i = 1; i < stalls.size(); ++i) {
            if (stalls[i]-stall>=distance) {
                cows++;
                stall = stalls[i];
                if (cows>=k) {
                    return true;
                }
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int start = 1;
        int end = stalls[n-1]-stalls[0];

        int ans = -1;

        while (start<=end) {
            int mid = start+(end-start)/2;
            if (isPossible(stalls,mid,k)) {
                ans = mid;
                start = mid+1;
            }else {
                end = mid-1;
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
        cout<<s.aggressiveCows(nums,k);
    }

    return 0;
}