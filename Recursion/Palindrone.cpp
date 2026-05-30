# include  <bits/stdc++.h>
using namespace std;

bool isPalindrone(vector<int> nums,int start,int end) {
    if (start>=end) {
        return true;
    }

    if (nums[start]!=nums[end]) {
        return false;
    }
    return isPalindrone(nums,start+1,end-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for(auto &x:nums)cin>>x;
        cout<<isPalindrone(nums,0,nums.size()-1);
    }

    return 0;
}