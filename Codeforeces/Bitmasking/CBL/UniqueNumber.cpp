//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3,1,2,3,4};
    int ans = 0;
    for (int x:nums) {
        ans = ans^x;
    }
    cout<<ans<<endl;
}
