# include  <bits/stdc++.h>
using namespace std;

void PrintReverse(vector<int> nums,int start,int end) {
    if (start==end) {
        return;
    }
    PrintReverse(nums,start+1,end);
    cout<<nums[start]<<" ";
}

void PrintArray(vector<int> nums,int start,int end) {
    if (start==end) {
        return;
    }
    cout<<nums[start]<<" ";
    PrintArray(nums,start+1,end);
}

int Sum(vector<int> nums,int start,int end,int sum) {
    if (start==end) {
        return 0;
    }
    return nums[start]+Sum(nums,start+1,end,sum);
}

int MinimumElement(vector<int> nums,int start,int end) {
    if (start==end-1) {
        return nums[start];
    }
    return min(nums[start],MinimumElement(nums,start+1,end));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n;cin>>n;
        vector<int> nums(n,0);
        for(auto &x:nums)cin>>x;
        PrintArray(nums,0,nums.size());
        cout<<endl;
        PrintReverse(nums,0,nums.size());
        cout<<endl;
        cout<<Sum(nums,0,nums.size(),0);
        cout<<endl;
        cout<<MinimumElement(nums,0,nums.size());
    }

    return 0;
}