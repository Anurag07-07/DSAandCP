//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int Count(int n) {
    int value = 0;
    while (n!=0) {
        value += n&1;
        n = n>>1;
    }
    return value;
}

int BinarytoDecimal(vector<int> nums) {
    int pow = 1;
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
        ans += nums[i]*pow;
        pow =  pow*2;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        int binary = Count(n);
        vector<int> nums;
        for (int i = 1; i <=binary; ++i) {
            nums.push_back(1);
        }
        int value = BinarytoDecimal(nums);
        cout<<value<<endl;
    }
}
