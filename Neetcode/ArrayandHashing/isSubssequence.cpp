//
// Created by anura on 11-05-2026.
//
//    i
// abc
//       j
// ahbgdc
//
// if i and j  matches increase both
// if both not matches increase j only




#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int i = 0;
        int j = 0;
        while (j<n) {
            if (s[i]==t[j]) {
                i++;
            }
            j++;
        }

        //if i reaches till s length
        return i==s.length();
    }
};

int main(int argc, char *argv[]) {
    string s = "axc";
    string t = "ahbgdc";
    Solution s1;
    cout<<s1.isSubsequence(s,t);

    return 0;
}
