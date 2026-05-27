//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    int t;cin>>t;
    while (t--) {
        string s;cin>>s;
        //Find the reverse of given string
        string r = s;
        reverse(r.begin(),r.end());
        //Add to make new string
        string n = s+"$"+r;
        //Create Lps array
        vector<int> lps(n.size(),0);
        int pref = 0;
        int suff = 1;
        while (suff<n.size()) {
            if (n[pref]==n[suff]) {
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

        //Take the Longest string which is p == s
        int already = lps[lps.size()-1];
        string left = s.substr(already);
        //Reverse the left string
        reverse(left.begin(),left.end());
        //Add it Into Original String
        string ans = left+s;
        cout<<ans<<endl;
    }
}
