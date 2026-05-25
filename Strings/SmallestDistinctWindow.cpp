//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s= "aabcbcdbca";

    int distinct = 0;
    vector<int> freq(256,0);
    for (char c:s) {
        if (freq[c]==0) {
            distinct++;
        }
        freq[c]++;
    }

    fill(freq.begin(),freq.end(),0);

    int i = 0;
    int j = 0;
    int ans = s.size();
    while (j<s.size()) {
        if (freq[s[j]]==0) {
            distinct--;
        }
        freq[s[j]]++;
        j++;
        while(distinct==0) {
            ans = min(ans,j-i);
            freq[s[i]]--;
            if (freq[s[i]]==0) {
                distinct++;
            }
            i++;
        }
    }
    cout<<ans<<endl;
}