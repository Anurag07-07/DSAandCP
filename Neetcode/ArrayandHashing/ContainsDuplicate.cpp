//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int x:nums) {
            if (s.count(x)) {
                return true;
            }

            s.insert(x);
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{1,2,3,1};
    Solution s;
    if (s.containsDuplicate(nums)) {
        cout<<"YES";
    }else {
        cout<<"NO";
    }
}
