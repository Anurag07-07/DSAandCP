//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int MaxElement(int start,int end,vector<int> nums) {
    if (start==end) {
        return 0;
    }
    return max(nums[start],MaxElement(start+1,end,nums));
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    vector<int> nums(n,0);
    for (auto &i:nums) cin>>i;
    cout<<MaxElement(0,nums.size(),nums);
}
