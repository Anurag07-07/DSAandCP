#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Solving(vector<int>& nums,int start,vector<int>& temp,vector<vector<int>>& ans) {
        if (start==nums.size()) {
            ans.push_back(temp);
            return;
        }

        //Not Include the Particular Element
        Solving(nums,start+1,temp,ans);
        //Include the Element
        temp.push_back(nums[start]);
        Solving(nums,start+1,temp,ans);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        Solving(nums,0,temp,ans);
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
        vector<vector<int>> ans = s.subsets(nums);
        for (vector<int> x:ans) {
            for (int y:x) {
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
