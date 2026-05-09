//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

void Reverse(vector<string>& nums,int start,int end) {
    //Base Case
    if (start>=end) {
        return;
    }

    //Swap the Start and end
    swap(nums[start],nums[end]);
    //Recursive Call
    Reverse(nums,start+1,end-1);
}

int main(int argc, char *argv[]) {
    vector<string> s{"h","e","l","l","o"};
    Reverse(s,0,s.size()-1);
    for (auto basic_string: s) {
        cout<<basic_string<<" ";
    }
}

