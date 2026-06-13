#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
        int n = 7;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
          int sum = 0;
          for (int j = 0; j < n; j++)
          {
            if (j==i)
            {
              sum+=a[j];
            }else{
              sum += (-1*a[j]);
            }
          }

          maxSum = max(maxSum,sum);
          
        }
        cout<<maxSum<<endl;
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