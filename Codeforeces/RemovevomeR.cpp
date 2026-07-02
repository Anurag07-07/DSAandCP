#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
        int n;
        cin >> n;
        
        vector<char> a(n);
        for (auto &x : a) cin >> x;


        if (n%2==0)
        {
          cout<<1<<endl;
        }else{
          cout<<2<<endl;
        }
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    Solution s;
    while (t--) {
        s.solve();
    }

    return 0;
}