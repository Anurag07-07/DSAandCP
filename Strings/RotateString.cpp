#include <bits/stdc++.h>
using namespace std;

void StringRotate(string &s) {
    char first = s[0];
    for (int i = 1; i < s.length(); ++i) {
        s[i-1] = s[i];
    }
    s[s.length()-1] = first;
}

int main(int argc, char *argv[]) {
    string s = "abcde";
    string goal = "cdeab";

    int n = s.length();
    for (int i = 1; i <= n; ++i) {
        StringRotate(s);
        if (s==goal) {
            cout<<"True"<<endl;
            return 0;
        }
    }
    cout<<"False"<<endl;
}
