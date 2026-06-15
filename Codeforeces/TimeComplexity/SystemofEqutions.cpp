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
        int m;
        cin >> m;
        int count = 0;

        for (int a = 0; a <= 1000; a++)
        {
          for (int b = 0; b <= 1000; b++)
          {
            if (((a*a)+b)==n && (a+(b*b))==m)
            {
              count++;
            }
          }
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