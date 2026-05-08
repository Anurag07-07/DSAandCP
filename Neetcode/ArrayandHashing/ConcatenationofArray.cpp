//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2*n);

    for (int i = 0; i < n; ++i) {
        ans[i] = ans[n+i] = nums[i];
    }

    return ans;
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,1};
    vector<int> ans = getConcatenation(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<" ";
    }
}
