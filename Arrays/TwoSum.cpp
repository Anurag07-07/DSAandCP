//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> Brute(vector<int> nums,int target) {
    for (int i = 0; i < nums.size()-1; ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i]+nums[j]==target) {
                return {i,j};
            }
        }
    }
    return {0};
}

vector<int> Optimal(vector<int> nums,int target) {
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int left = target-nums[i];
        if (map.count(left)) {
            return {i,map[left]};
        }
        map.insert({nums[i],i});
    }
    return {0};
}
int main(int argc, char *argv[]) {
    vector<int> nums{2,7,11,15};
    Optimal(nums,9);
}
