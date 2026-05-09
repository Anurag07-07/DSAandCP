//
// Created by anura on 09-05-2026.
//
//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
    c = tolower(c);

    return (c == 'a' || c == 'e' ||
            c == 'i' || c == 'o' ||
            c == 'u');
}




int CountVowel(string s,int start,int end) {
    //Base Case
    if (start==end) {
        if (isVowel(s[start])) {
            return 1;
        }else {
            return 0;
        }
    }
    // Recursive Call
    // Total Vowel  = Current Char is vowel or not + Total Vowel in left string
    if (isVowel(s[start])) {
        return 1+CountVowel(s,start+1,end);
    }
    return CountVowel(s,start+1,end);
}

int main(int argc, char *argv[]) {
    string s = "Someoneisthereforme";
    cout<<CountVowel(s,0,s.length()-1);
}
