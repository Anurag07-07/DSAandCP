//
// Created by anura on 11-05-2026.
#include <bits/stdc++.h>
using namespace std;

void Create(vector<int> &nums,int start,int end,vector<int> &temp,vector<vector<int>> &ans) {
    //Base Case
    //When start become equal to end it means whole array iss iteratored so we have to put the temp(carry some element) inside the ans (Carry Temp)
    if (start==end) {
        ans.push_back(temp);
        return;
    }

    //Current Element is not Considered
    Create(nums,start+1,end,temp,ans);
    //Current Element is Considered
    temp.push_back(nums[start]);
    Create(nums,start+1,end,temp,ans);
    //Remove the Element insert inside the temp to save space
    temp.pop_back();
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3};
    vector<int> temp;
    vector<vector<int>> ans;
    Create(nums,0,nums.size(),temp,ans);

    for (auto array:ans) {
        for (int x:array) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
