#include <bits/stdc++.h>
using namespace std;
int Brute(vector<int> nums) {

    int n = nums.size();
    int water = 0;

    for (int i = 0; i < n; ++i) {
        int left = INT_MIN;
        int right = INT_MIN;
        for (int j = i; j >=0 ; j--) {
            left = max(left,nums[j]);
        }
        for (int j = i; j < n ; j++) {
            right = max(right,nums[j]);
        }

        //Find the Water
        water += min(left,right)-nums[i];
    }
    return water;
}

int Better(vector<int> nums) {

    int n = nums.size();
    int water = 0;

    vector<int> psum(n,0);
    vector<int> ssum(n,0);
    psum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        psum[i] = max(psum[i-1],nums[i]);
    }

    ssum[n-1] = nums[n-1];
    for (int i = n-2; i >=0 ; --i) {
        ssum[i] = max(ssum[i+1],nums[i]);
    }

    for (int i = 0;i<n;i++) {
        water += min(psum[i],ssum[i])-nums[i];
    }
    return  water;
}

int Optimal(vector<int> nums) {
    int n = nums.size();
    int leftmax = 0;
    int rightmax = 0;
    int i = 0;int j = n-1;
    int water = 0;
    while (i<j) {
        if (nums[i]<=nums[j]) {
            if (nums[i]>=leftmax) {
                leftmax = nums[i];
            }else {
                water += (leftmax-nums[i]);
            }
            i++;
        }else {
            if (nums[j]>=rightmax) {
                rightmax = nums[j];
            }else {
                water += (rightmax-nums[j]);
            }
            j--;
        }
    }
    return  water;
}


int main(int argc, char *argv[]) {
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<Better(nums);
    cout<<Optimal(nums);
}
