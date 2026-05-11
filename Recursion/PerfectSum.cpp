//
// Created by anura on 11-05-2026.
//
#include<bits/stdc++.h>
using namespace std;

int Subset(vector<int> nums,int start,int end,int sum) {

    //Base Case
    //If I reach till last index
    //and i got sum == 0 i will return 1
    //If sum!=0 I will return 0
    if (start==end) {
        return sum==0;
    }

    //If we Consider the Single Either It Contribute in sum or not

    //If it contribute
    int path1 = Subset(nums,start+1,end,sum-nums[start]);
    //If It Not COntribute
    int path2 = Subset(nums,start+1,end,sum);
    //We have to add all the occurance that will come through either selecting or not selecting the element
    return path1+path2;
}

int main(int argc, char *argv[]) {
    vector<int> nums{5,2,3,6,10,8};
    int target = 10;

    cout<<Subset(nums,0,nums.size(),target);
}
