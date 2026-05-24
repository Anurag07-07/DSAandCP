//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s = "is2 sentence4 This1 a3";
    //Calculate Total Words
    vector<string> ans(10,"");
    int i = 0;

    string temp;
    int count = 0;
    while (i<s.length()) {
        if (s[i]==' ') {
            //Find the Position
            int pos = temp[temp.size()-1]-'0';
            //Remove the last char
            temp.pop_back();
            //Put the string on the pos
            ans[pos] = temp;
            //Find the
            temp.clear();
            count++;
        }else {
            temp += s[i];
        }
        i++;
    }
    int pos = temp[temp.size()-1]-'0';
    //Remove the last char
    temp.pop_back();
    //Put the string on the pos
    ans[pos] = temp;
    //Find the
    temp.clear();
    count++;

    string result = "";
    for (int m = 1; m <= count; ++m) {
        result += (ans[m]);
        result += " ";
    }

    result.pop_back();
    return 0;
}
