#include <bits/stdc++.h>
using namespace std;

void PrintWay1(int value,int n) {

    if (value>n) {
        return;
    }

    cout<<value<<" ";
    PrintWay1(value+1,n);
}

void PrintWay2(int n) {

    if (n<=0) {
        return;
    }

    PrintWay2(n-1);
    cout<<n<<" ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        PrintWay2(n);
    }

    return 0;
}
