#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    vector<int> nums{4,3,2,1,2,7,6};
    int n = nums.size();

    vector<int> ans;

    //The Correct Index where a particular Element Store
    for (int i = 0; i < nums.size(); ++i) {
        nums[i]--;
    }

    //Now Increase the Occurance of An Element
    for (int i = 0; i < nums.size(); ++i) {
        nums[nums[i]%n] += n;
    }

    //Find the Missing Element
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]/n==0) ans.push_back(i+1);
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i]/n==2) ans.push_back(i+1);
    }
    
    for (int x:ans) {
        cout<<x<<" ";
    }
}
