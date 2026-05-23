//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool Brute(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j <=i; ++j) {
            sum1+=nums[j];
        }
        for (int j = i+1; j < n; ++j) {
            sum2+=nums[j];
        }
        if (sum1==sum2) {
            return true;
        }
    }
    return false;
}

bool Better(vector<int> nums) {
    int n = nums.size();
    vector<int> psum(n,0);
    psum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        psum[i] = psum[i-1]+nums[i];
    }

    for (int i = 0; i < psum.size(); ++i) {
          int left = psum[i];
          int right = psum[n-1]-psum[i];
        if (left==right) {
            return true;
        }
    }
    return false;
}


bool Optimal(vector<int> nums) {
    int n = nums.size();
    //Find the Total Sum
    int total = 0;
    for (int x:nums) {
        total+=x;
    }

    int left = nums[0];
    for (int i = 0; i < n; ++i) {
        int right = total-left;
        if (left==right) {
            return true;
        }
        if (i>0)
        left += nums[i];
    }
    return false;
}
int main(int argc, char *argv[]) {
    vector<int> nums{3,4,-2,5,3,20,-10,8};
    cout<<Brute(nums);
    cout<<Better(nums);
}
