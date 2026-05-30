#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);

    return ch == 'a' ||
           ch == 'e' ||
           ch == 'i' ||
           ch == 'o' ||
           ch == 'u';
}
int VowelCount(string s,int start,int end) {
    if (start==end) {
        return 0;
    }

    return isVowel(s[start])+VowelCount(s,start+1,end);
}

void Reverse(string &s ,int start,int end) {
    if (start>end) {
        return;
    }
    swap(s[start],s[end]);
    Reverse(s,start+1,end-1);
}

void ChangeCase(string &s,int start,int end) {
    if (start==end) {
        return;
    }
    if (s[start]>='a' && s[start]<='z') {
        s[start] = (s[start]-'a')+'A';
    }
    ChangeCase(s,start+1,end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;cin>>s;
        cout<<VowelCount(s,0,s.length());
        cout<<endl;
        // Reverse(s,0,s.length()-1);
        cout<<s<<endl;
        ChangeCase(s,0,s.length());
        cout<<endl;
        cout<<s<<endl;
    }

    return 0;
}
