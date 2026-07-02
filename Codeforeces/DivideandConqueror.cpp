#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
        int x,y;
        cin >> x >> y;
       for (int i = 1; i < 101; i++)
       {
         if (y*i==x)
         {
           cout<<"YES"<<endl;
           return;
          }
          
          if (y*i>x)
          {
            break;
          }
          
       }

       cout<<"NO"<<endl;
        
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