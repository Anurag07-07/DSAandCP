//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int Brute(vector<int> nums) {
    int n = nums.size();
    int max_diff = INT_MIN;
    for (int i = 0; i <= n-2; ++i) {
        for (int j = i+1; j <= n-1; ++j) {
            int diff = nums[j]-nums[i];
            max_diff = max(max_diff,diff);
        }
    }
    return max_diff;
}

int Better(vector<int> nums) {
    int n = nums.size();
    vector<int> psum(n,0);
    psum[n-1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        psum[i] = max(psum[i+1],nums[i+1]);
    }

    for (int x:psum) {
        cout<<x<<" ";
    }

    cout<<endl;

    int max_diff = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int diff = psum[i]-nums[i];
        max_diff = max(max_diff,diff);
    }
    return max_diff;
}
int main(int argc, char *argv[]) {

    vector<int> nums{9,5,8,12,2,3,7,4};
    // cout<<Brute(nums);
    cout<<Better(nums);
}
