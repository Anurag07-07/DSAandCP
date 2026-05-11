//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //Remove the Space from last and start
        int start = 0;
        int end = s.length()-1;
        while (start <= end && s[start] == ' ') {
            start++;
        }

        // Remove trailing spaces
        while (end >= start && s[end] == ' ') {
            end--;
        }

        string t = s.substr(start, end - start + 1);


        int i = t.length()-1;
        while (i>=0) {
            if(t[i]==' '){
                break;
            }
            i--;
        }
        return (t.length()-i)-1;
    }
};

int main(int argc, char *argv[]) {
    Solution s1;
      string s = "a";
      cout<<s1.lengthOfLastWord(s);
}
