//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
    if (c=='a' || c=='A') return true;
    else if (c=='e' || c=='E') return true;
    else if (c=='i' || c=='I') return true;
    else if (c=='o' || c=='O') return true;
    else if (c=='u' || c=='U') return true;
    return false;
}
int main(int argc, char *argv[]) {
    string s;cin>>s;
    //for Storing Vowels i will create 256 size array
    vector<int> freq(256,0);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isVowel(c)) {
            freq[c]++;
            s[i]='#';
        }
    }

    //Create a sorted String
    string sorted;
    for (int i = 0; i < freq.size(); ++i) {
        while (freq[i]-->0) {
            sorted+=char(i);
        }
    }

    //Use two pointer to sort the Vowels
    int i = 0;
    int j = 0;
    while (i<s.length() && j< sorted.size()) {
        if (s[i]=='#') {
            s[i]=sorted[j++];
        }
        i++;
    }
    cout<<s<<endl;
}
