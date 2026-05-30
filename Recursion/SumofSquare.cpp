#include <bits/stdc++.h>
using namespace std;

int SumofSquare(int n) {
    if (n==0) {
        return 0;
    }

    return (n*n)+SumofSquare(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout<<SumofSquare(5);
    }

    return 0;
}
