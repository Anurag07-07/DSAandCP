#include <bits/stdc++.h>
using namespace std;

void PrintEven(int n) {
    if (n<=0) {
        return;
    }

    printf("%d ",n);
    PrintEven(n-2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        PrintEven(n);
    }

    return 0;
}
