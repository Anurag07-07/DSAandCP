#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int start = 0;
        int end = m;
        while(start<=end){
            int cut1 = start+(end-start)/2;
            int cut2 = ((m+n+1)/2)-cut1;

            int leftmax1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int leftmax2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            int rightmin1 = cut1==m ? INT_MAX : nums1[cut1];
            int rightmin2 = cut2==n ? INT_MAX : nums2[cut2];

            if(leftmax1<=rightmin2 && leftmax2<=rightmin1){
                if((m+n)%2==0){
                    return (max(leftmax1,leftmax2)+min(rightmin1,rightmin2))/2.0;
                }else{
                    return max(leftmax1,leftmax2);
                }
            }else if(leftmax1>rightmin2){
                end = cut1-1;
            }else{
                start = cut1+1;
            }

        }
        return 0.0;
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
        int m;
        cin >> m;
        vector<int> nums1(n, 0);
        for (auto &x: nums1)cin >> x;
        vector<int> nums2(m, 0);
        for (auto &x: nums2)cin >> x;
        cout<<s.findMedianSortedArrays(nums1,nums2);
    }
    return 0;
}
