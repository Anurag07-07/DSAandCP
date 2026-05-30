# include  <bits/stdc++.h>
using namespace std;

int GCD(int a,int b) {
    if (a==0) {
        return b;
    }
    return (a%b,a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;

    while (t--) {
        int n1;cin>>n1;
        int n2;cin>>n2;
        cout<<GCD(n1,n2);
    }

    return 0;
}