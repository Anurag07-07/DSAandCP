#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
      int x,y,n;cin>>x>>y>>n;
      //Find the Closest value
      //Find the Closest vale that is divisible by x
      //Find the Remainder
      int rem = n%x;
      int value = n-rem; 
      if (value%x==y)
      {
        cout<<value<<endl;
        return;
      }else if (value+y<=n)
      {
        cout<<value+y<<endl;
      }else{
        value = value-x+y;
        cout<<value<<endl;
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