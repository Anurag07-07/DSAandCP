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

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int maxi = *max_element(a.begin(),a.end());
        int count = 0;
        for (int i = 0; i < a.size(); i++)
        {
          count += abs(maxi-a[i]);
        }

        cout<<count<<endl;
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
        s.solve();

    return 0;
}