//
// Created by anura on 11-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

void SumofSubset(vector<int> nums,int start,int end,vector<int> &temp,int sum) {
    //Base Case
    //If i reach till last index i will store the sum inside temp
    if (start==end) {
        temp.push_back(sum);
        return;
    }

    //Two Option for a particular Element Either we add it into sum or not
    //If Not added
    SumofSubset(nums,start+1,end,temp,sum);
    //If Added
    SumofSubset(nums,start+1,end,temp,sum+nums[start]);
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3};
    vector<int> temp;
    SumofSubset(nums,0,nums.size(),temp,0);
    for (int x:temp) {
        cout<<x<<" ";
    }
}


