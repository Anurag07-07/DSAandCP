//
// Created by anura on 09-05-2026.
//

#include <bits/stdc++.h>
using namespace std;
bool isPalindrone(string s,int start,int end) {
    //Base Case
    if (start==end) {
        return true;
    }

    //Recursive Call
    //Check if the start and end are equal or not
    if (s[start]!=s[end]) {
        return false;
    }

    return isPalindrone(s,start+1,end-1);
}
int main(int argc, char *argv[]) {
    string s = "Anurag";
    cout<<isPalindrone(s,0,s.length()-1);
}
