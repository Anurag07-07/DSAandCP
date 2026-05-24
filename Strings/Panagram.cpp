//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s = "thequickbrownfoxjumpsoverthelazydog";

    vector<int> freq(26,0);

    for (int i = 0; i < s.length(); ++i) {
        freq[s[i]-'a']++;
    }
    for (int x:freq) {
        if (x<=0) {
            cout<<"False"<<endl;
            return 0;
        }
    }
    cout<<"True"<<endl;
    return 0;
}
