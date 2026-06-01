#include <bits/stdc++.h>
using namespace std;

//To Prevent th Space Complexity
void PermuBetter(vector<int> &nums,int index,vector<vector<int>> &ans) {
    if (index==nums.size()) {
        ans.push_back(nums);
        return;
    }

    //Index tell that before that position element are fixed and now from that position we have to chcek how make combination we can create
    vector<bool> use(21,0);
    for (int i = index;i<nums.size();i++) {
        if (use[nums[i]+10]==0) {
            use[nums[i]+10] = 1;
            swap(nums[index],nums[i]);
            PermuBetter(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }
}


vector<vector<int>> Permutation(vector<int> &nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    vector<int> visited(nums.size(),0);
    PermuBetter(nums,0,ans);
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
        vector<vector<int>> ans = Permutation(nums);
        for (vector<int> &y:ans) {
            for (int x:y) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
