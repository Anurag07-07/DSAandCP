#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    bool isPrime(int x){
      for (int i = 2; i*i <= x; i++)
      {
        if (x%i==0)
        {
          return false;
        }
        
      }
      return true;
      
    }
    void solve() {
        int n;
        cin >> n;
        //Find the First Number which is not prime 
        for (int i = 2; i < INT_MAX; i++)
        {
          if (!isPrime(i))
          {
            int val = i+n;
            if (val<=INT_MAX && !isPrime(val))
            {
              cout<<val<<" "<<i<<endl;
              return;
            }
          }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
        s.solve();

    return 0;
}