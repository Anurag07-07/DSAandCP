//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int Subset(vector<int> nums,int start,int end,int sum) {
    //Base Case
    if (sum==0) {
        return 1;
    }
    if (start==end || sum<0) {
        return 0;
    }

    //If We Consider element contribute into sum but dont increase the start pointer
    //If not Include increase the pointer
    return Subset(nums,start+1,end,sum)+Subset(nums,start,end,sum-nums[start]);
}

int main(int argc, char *argv[]) {
    vector<int> nums{2,3,4};
    int target = 6;

    cout<<Subset(nums,0,nums.size(),target);
}
