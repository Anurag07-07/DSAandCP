//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> Optimal(vector<int> nums,int target) {
    int i = 0;int j = nums.size()-1;
    while (i<j) {
        int sum = nums[i]+nums[j];
        if (sum==target) {
            return {i+1,j+1};
        } else if (sum>target) {
            j--;
        }else {
            i++;
        }
    }
    return {-1,-1};
}
int main(int argc, char *argv[]) {
    vector<int> nums{2,7,11,15};
    int target = 9;
    Optimal(nums,target);
}
