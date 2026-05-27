//
// Created by anura on 27-05-2026.
//
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool KMPAlgorithm(string haystack,string needle) {
        int n = haystack.size();
        vector<int> lps(n,0);
        int pref = 0;
        int suff = 1;
        while (suff<n) {
            if (needle[pref]==needle[suff]) {
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

        int i = 0;
        int j = 0;

        while (i<haystack.size() && j<needle.size()) {
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
            return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {

        if (a.size()==b.size()) {
            return -1;
        }

        string temp = a;
        int repeat = 1;
        while (temp.size()<b.size()) {
            temp+=a;
            repeat++;
        }

        //Apply KMP String Matching Algorithm
        if (KMPAlgorithm(temp,b)) {
            return repeat;
        }

        if (KMPAlgorithm(temp+a,b)) {
            return repeat+1;
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    int t;cin>>t;
    Solution s;
    while (t--) {
        string a;cin>>a;
        string b;cin>>b;

        cout<<s.repeatedStringMatch(a,b);
    }
}

