#include <bits/stdc++.h>
using namespace std;

void Print(int n) {
    if (n<=0) return;
    cout<<n<<" ";
    Print(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n;cin>>n;
        Print(n);
    }

    return 0;
}