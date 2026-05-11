//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
//             i
// s = coaching
//
//       j
// t = coding
//     012345
// if both are equal increase the i and j
// if both are not equal increse i
// //SO i have to add t.length()-j character in s
//       i
// s = "abcde"
//       j
// t = "a"
//
// stoping condition maybe i<s.length() && j<t.length()



class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while (i<s.length()) {
            if (s[i]==t[j]) {
                j++;
            }
            i++;
        }

        cout<<i<<" "<<j<<endl;

        //Count the total Character
        return t.size()-j;
    }
};


int main(int argc, char *argv[]) {
    // string s = "coaching";
    // string t = "coding";
    string s = "z";
    string t = "abcde";
    Solution s1;
    cout<<s1.appendCharacters(s,t);
}
