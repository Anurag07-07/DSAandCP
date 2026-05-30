#include <bits/stdc++.h>
using namespace std;

int FibonacciSeries(int n) {
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }

    return FibonacciSeries(n-1)+FibonacciSeries(n-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout<<FibonacciSeries(n);
    }

    return 0;
}
