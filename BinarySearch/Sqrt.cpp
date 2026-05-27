//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
        int ans = x;
        while (start<=end) {
            int mid = start+(end-start)/2;
            if (mid==x/mid) {
                return mid;
            }else if (mid>x/mid) {
                end = mid-1;
            }else {
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    int t;cin>>t;
    Solution s;
    while (t--) {
        int value;cin>>value;
        cout<<s.mySqrt(value);
    }
}
