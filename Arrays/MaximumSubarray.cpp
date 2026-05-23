//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int Brute(vector<int> nums) {
    int n = nums.size();
    int max_sum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum+=nums[k];
            }
            max_sum = max(sum,max_sum);
        }
    }
    return max_sum;
}

int Better(vector<int> nums) {
    int n = nums.size();
    vector<int> psum(n,0);
    psum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        psum[i] = psum[i-1]+nums[i];
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = 0;
            if (i==0) {
                sum = psum[j];
            }else {
                sum = psum[j]-psum[i-1];
            }
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
}

int Optimal(vector<int> nums) {
    int max_sum = INT_MIN;
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=nums[i];
        max_sum = max(max_sum,sum);
        if (sum<0) sum = 0;
    }
    return max_sum;
}

int main(int argc, char *argv[]) {
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout<<Brute(nums);
    cout<<Better(nums);
    cout<<Optimal(nums);
}
