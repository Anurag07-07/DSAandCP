//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int Brute(vector<vector<int>> nums) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i][i]+nums[i][n-i-1];
    }

    if (n%2==1) {
       sum  = sum - nums[n/2][n/2];
    }

    cout<<sum<<endl;
}
int main(int argc, char *argv[]) {
    vector<vector<int>> nums{
        {5,8,3},
        {6,2,8},
        {5,3,2}};
    Brute(nums);
}
