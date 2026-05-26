//
// Created by anura on 26-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPrefix(string s) {
        int pref = 0;int suff = 1;
        int n = s.size();
        vector<int> lps(n,0);
        while (suff<n) {
            if (s[pref]==s[suff]) {
                lps[suff] = pref+1;
                pref++;
                suff++;
            }else {
                if (pref==0) {
                    lps[suff++] = 0;
                }else {
                    pref = lps[pref-1];
                }
            }
        }

        //Find the string to cut
        int cut = lps[lps.size()-1];
        s = s.substr(0,cut);
        return s;
    }
};
int main(int argc, char *argv[]) {
    int t;cin>>t;
    Solution s;
    while (t--) {
        string s1;cin>>s1;
        cout<<s.longestPrefix(s1)<<endl;
    }
}
