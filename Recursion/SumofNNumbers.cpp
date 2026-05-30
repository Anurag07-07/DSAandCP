#include <bits/stdc++.h>
using namespace std;

int Summition(int n) {
    if (n==0) {
        return 0;
    }
    return n+Summition(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout<<Summition(n);
    }

    return 0;
}
