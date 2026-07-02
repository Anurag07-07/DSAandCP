#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    bool Good(long long x){
      unordered_map<long long,long long> mp;
      while (x!=0)
      {
        long long lastdigit = x%10;
        mp[lastdigit]++;
        x/=10;
      }

      int count = 0;
      for (auto i = mp.begin(); i != mp.end(); i++)
      {
        if (i->second!=0)
        {
          count++;
        }
      }
      
      return count<=2;
    }
    void solve() {
        int x;
        cin >> x;
        int  y = 2;
        while (y<10000)
        {
          bool isGood = Good(y);
          if (isGood)
          {
            long long multi = x*y;
            if (Good(multi))
            {
              cout<<y<<endl;
              break;
            }  
          }
          y++;
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