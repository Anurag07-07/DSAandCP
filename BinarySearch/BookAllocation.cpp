#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long> books,int min_page,int students) {
    long count = 1;
    long long pages = 0;
    for (auto x:books) {
        pages+=x;
        if (pages>min_page) {
            count++;
            pages = x;
            if (count>students) {
                return false;
            }
        }
    }
    return true;
}

long long allocateBooks(vector<long long>& books, int N, int M) {
    if (M>N) return -1;
    long long start = *max_element(books.begin(),books.end());
    long long end  = accumulate(books.begin(),books.end(),0LL);
    long long ans = 0;
    while (start<=end) {
        long long mid = start+(end-start)/2;
        if (isPossible(books,mid,M)) {
            ans = mid;
            end = mid-1;
        }else {
            start = mid+1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N;cin>>N;
        vector<long long> nums(N, 0);
        for (auto &x: nums)cin >> x;
        int M;cin>>M;
        cout<<allocateBooks(nums,N,M);
    }
    return 0;
}
