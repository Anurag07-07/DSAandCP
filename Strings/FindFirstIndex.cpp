//
// Created by anura on 26-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStrBrute(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <=n-m ; ++i) {
            int first = i;int second = 0;
            while (second<m) {
                if (haystack[first]==needle[second]) {
                    first++;
                    second++;
                }else {
                    break;
                }
            }
            if (second==m) {
                return first-second;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        //Create LPS table First
        int m= needle.size();
        int n= haystack.size();
        int pref = 0;
        int suff = 1;
        vector<int> lps(m,0);
        while (suff<m) {
            if (needle[pref]==needle[suff]) {
                lps[suff] = pref+1;
                pref++;
                suff++;
            }else {
                if (pref==0) {
                    lps[suff] = 0;
                    suff++;
                }else {
                    pref = lps[pref-1];
                }
            }
        }

        //Apply KMP algorithm
        int i = 0;
        int j = 0;
        while (i<n && j<m) {
            //First Case
            if (haystack[i]==needle[j]) {
                i++;
                j++;
            }else {
                if (j==0) {
                    i++;
                }else {
                    j = lps[j-1];
                }
            }
        }
        if (j==needle.size()) {
            return i-j;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    int t;cin>>t;
    Solution s;
    while (t--) {
        string s1;cin>>s1;
        string s2;cin>>s2;
        cout<<s.strStr(s1,s2)<<endl;
    }
}
