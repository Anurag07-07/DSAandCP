//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

//Sum of 5 element is Equal = Element + sum of 4 element
//Sum of 4 element is Equal = Element + sum of 3 element
//Sum of n element is Equal = Element + sum of n-1 element

int SumofElement(vector<int> nums,int start,int end) {
    //Base Case
    // When End and Start at same point return 0 as end is at n index the sum of n index is 0
    if (start==end) {
        return 0;
    }

    return nums[start]+SumofElement(nums,start+1,end);
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3,4,5};
    cout<<SumofElement(nums,0,nums.size());
}
