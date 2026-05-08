//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& nums ,int start,int mid,int end) {
    //Create a Temp Array
    int i = start;
    int j = mid+1;
    vector<int> temp(end-start+1);
    int k = 0;

    //Merge the Two Arrays
    while (i<=mid && j<=end) {
        if (nums[i]>=nums[j]) {
            temp[k++] = nums[j++];
        }else {
            temp[k++] = nums[i++];
        }
    }

    //Store Left Element
    while (i<=mid) {
        temp[k++] = nums[i++];
    }

    while (j<=end) {
        temp[k++] = nums[j++];
    }

    //Now Store all the Element in Original Array
    for (int x = 0; x < temp.size(); ++x) {
        nums[start+x] = temp[x];
    }
}

void MergeSort(vector<int>& nums,int start,int end) {
    if (start==end) {
        return;
    }

    //Find the mid
    int mid = start+(end-start)/2;
    //Split
    MergeSort(nums,start,mid);
    MergeSort(nums,mid+1,end);
    Merge(nums,start,mid,end);
}

int main(int argc, char *argv[]) {
    vector<int> nums{5,4,6,5,4,1,2,1,3};
    MergeSort(nums,0,nums.size()-1);

    for (auto x: nums) {
        cout<<x<<" ";
    }
}
