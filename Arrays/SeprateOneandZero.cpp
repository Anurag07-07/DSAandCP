//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void Brute(vector<int> arr) {
    int n = arr.size();
    //Find all zeroes and Ones Count
    int zeros = 0;
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i]==0) zeros++;
        if (arr[i]==1) ones++;
    }

    //Store all zeroes
    vector<int> ans;
    for (int i = 1; i <= zeros; ++i) {
        ans.push_back(0);
    }
    for (int i = 1; i <= ones; ++i) {
        ans.push_back(1);
    }

    for (int x:ans) {
        cout<<x<<" ";
    }
}

void Optimal(vector<int> nums) {
    int n = nums.size();
    int i = 0;
    int j = n-1;
    while (i<=j) {
        if (nums[i]==0) {
            i++;
        }else {
            if (nums[j]==0) {
                swap(nums[i],nums[j]);
            }else {
                j--;
            }
        }
    }
    for (int x:nums) {
        cout<<x<<" ";
    }
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,0,1,0,0,0,0,1,0,1,1,1,1};
    // Brute(nums);
    cout<<endl;
    Optimal(nums);
}
