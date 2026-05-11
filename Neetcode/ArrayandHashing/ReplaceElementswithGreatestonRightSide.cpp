//
// Created by anura on 11-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> psum(nums.size(),0);
        psum[n-1] = -1;

        for (int i = n - 2; i >= 0; --i) {
            psum[i] = max(nums[i+1],psum[i+1]);
        }

        for (int x:psum) {
            cout<<x<<" ";
        }

        return psum;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{17,18,5,4,6,1};
    Solution s;
    s.replaceElements(nums);
}
