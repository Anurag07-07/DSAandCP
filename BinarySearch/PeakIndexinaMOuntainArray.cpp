#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while (start<=end) {
            int mid = end+(start-end)/2;
            if (arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
                return mid;
            } else if (arr[mid]>=arr[mid-1]) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution s;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (auto &x: nums)cin >> x;
        cout<<s.peakIndexInMountainArray(nums)<<endl;
    }

    return 0;
}
