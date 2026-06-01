#include <bits/stdc++.h>
using namespace std;

void Sum(vector<int> nums,vector<int>& temp,int start,int end,vector<int>& ans) {
    if (start == end) {
        int sum = accumulate(temp.begin(),temp.end(),0);
        ans.push_back(sum);
        return ;
    }

//  Not Inclded
    Sum(nums,temp,start+1,end,ans);
    //Include
    temp.push_back(nums[start]);
    Sum(nums,temp,start+1,end,ans);
    temp.pop_back();

}

vector<int> SubsetSums(vector<int> nums) {
    vector<int> temp;
    vector<int> ans;
    Sum(nums,temp,0,nums.size(),ans);
    return ans;
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
        vector<int> ans = SubsetSums(nums);
        for (int x:ans) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}
