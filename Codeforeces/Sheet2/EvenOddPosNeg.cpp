//
// Created by anura on 23-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int n;cin>>n;
    vector<int> nums(n,0);
    for (auto &i:nums) cin>>i;
    int even = 0;
    int odd = 0;
    int positive = 0;
    int negative = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]%2==0) {
            even++;
        } if (nums[i]%2==1 || nums[i]%2==-1) {
            odd++;
        } if (nums[i]>0) {
            positive++;
        } if (nums[i]<0) {
            negative++;
        }
    }

    cout<<"Even: "<<even<<endl;
    cout<<"Odd: "<<odd<<endl;
    cout<<"Positive: "<<positive<<endl;
    cout<<"Negative: "<<negative<<endl;
}
