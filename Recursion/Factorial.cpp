#include <bits/stdc++.h>
using namespace std;

int Factorial(int n) {
    if (n==0) {
        return 1;
    }
    return n*Factorial(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout<<Factorial(n);
    }

    return 0;
}
