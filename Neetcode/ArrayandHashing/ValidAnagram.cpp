//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 bool isAnagram(string s, string t) {
     if (s.size()!=t.size())
         return false;


    //Create a Frequency Array
     vector<int> freq(26,0);

     for (int i = 0; i < s.length(); ++i) {
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
     }


     //Check if any char left
     for (auto x: freq) {
         if (x>0) {
             return false;
         }
     }
     return true;
 }
};

int main(int argc, char *argv[]) {
 string s = "anagram", t = "nagaram";
 Solution s1;
 if (s1.isAnagram(s,t)) {
   cout<<"YES"<<endl;
 }else {
     cout<<"NO"<<endl;
 }

 return 0;
}
