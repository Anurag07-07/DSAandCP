#include <vector>
//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void Print(vector<int> nums,int start,int end) {
    //Base Condition
    if (start>=end) {
        return;
    }

    //Print The Current Element
    cout<<nums[start]<<" ";
    // Calling the function
    Print(nums,start+1,end);
}

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3,4,5};
    Print(nums,0,nums.size());
}
