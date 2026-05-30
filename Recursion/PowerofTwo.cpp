#include <bits/stdc++.h>
using namespace std;

int PowerofTwo(int n) {
    if (n==0) {
        return 1;
    }
    return 2*PowerofTwo(n-1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout<<PowerofTwo(n);
    }

    return 0;
}
