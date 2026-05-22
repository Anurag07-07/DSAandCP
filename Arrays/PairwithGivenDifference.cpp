//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool Optimal(vector<int> nums,int target) {
    sort(nums.begin(),nums.end());
    //If Target is Negative
    if (target<0) {
        target = -1*target;
    }
    int i = 0;int j = 1;
    while (j<nums.size()) {
        int sub = nums[j]-nums[i];
        if (sub==target) {
            return true;
        }else if (sub>target) {
            i++;
        }else {
            j++;
        }
        //If I and J are on same position
        if (i==j) {
            j++;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    cout<<"Enter Test Cases"<<endl;
    int t;cin>>t;
    while (t--) {
        cout<<"Enter Size of Array"<<endl;
        int n;cin>>n;
        cout<<"Enter Element"<<endl;
        vector<int> nums(n,0);
        for (auto &x:nums) {
            cin>>x;
        }
        cout<<Optimal(nums,45);
    }
}
