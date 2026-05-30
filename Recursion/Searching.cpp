# include  <bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int> nums,int start,int end,int target) {
    if (start==end) {
        return false;
    }
    if (nums[start]==target) {
        return true;
    }
    return LinearSearch(nums,start+1,end,target);
}

bool BinarySearch(vector<int> nums,int start,int end,int target) {
    if (start>end) {
        return false;
    }

    int mid = start+(end-start)/2;

    if (nums[mid]==target) {
        return true;
    }else if (nums[mid]>target) {
        return BinarySearch(nums,start,mid-1,target);
    }else {
        return BinarySearch(nums,start+1,end,target);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for(auto &x:nums)cin>>x;
        int target;cin>>target;
        cout<<LinearSearch(nums,0,nums.size(),target)<<endl;
        cout<<BinarySearch(nums,0,nums.size(),target)<<endl;
    }

    return 0;
}