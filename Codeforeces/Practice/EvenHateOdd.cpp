//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t-->0) {
        int n;cin>>n;
        vector<int> arr(n);
        for (auto &i:arr)cin>>i;
        if (n%2==1) {
            cout<<-1<<endl;
        }else {
            int even = 0;
            int odd = 0;
            for (int i = 0; i < arr.size(); ++i) {
                if (arr[i]%2==0) {
                    even++;
                }else {
                    odd++;
                }
            }
            int diff;
            if (even>odd) {
                diff = even-n/2;
            }else {
                diff = odd-n/2;
            }
            cout<<diff<<endl;
        }
    }
}
