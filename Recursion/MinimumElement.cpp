//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;


// Minimum  of 5 element is min(current elment, minimum from other 4 element)
// Minimum  of 4 element is min(current elment, minimum from other 3 element)

int Minimum(vector<int> nums,int start,int end) {

    //Base Case
    if (start==end) {
        return nums[end];
    }

    //Function Call
    return  min(nums[start],Minimum(nums,start+1,end));
}

int main(int argc, char *argv[]) {
    vector<int> nums{4,5,6,5,1,3};
    cout<<Minimum(nums,0,nums.size()-1);

}
