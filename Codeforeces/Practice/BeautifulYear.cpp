//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n) {
    unordered_set<int> s;
    while (n!=0) {
        s.insert(n%10);
        n/=10;
    }
    return s.size()==4;
}
int main(int argc, char *argv[]) {
    int n;cin>>n;
    n++;
    while (true) {
        if (isPossible(n)) {
            cout<<n<<endl;
            return 0;
        }
        n++;
    }
}

