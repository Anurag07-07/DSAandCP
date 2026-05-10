//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

bool TargetValue(vector<int> nums,int start,int end,int target) {
    //Base Case
    //If Target Become Zero it means Some Element are there whose sum subtracting from target make target zero
    if (target==0) return true;
    if (start==end || target<0) return false;

    //For a particular Element there are two either it contribute to sum or not
    return TargetValue(nums,start+1,end,target) || TargetValue(nums,start+1,end,target-nums[start]);
}

int main(int argc, char *argv[]) {
    vector<int> nums{3,6,4,5};
    int target = 12;
    if (TargetValue(nums,0,nums.size(),target)) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
}
