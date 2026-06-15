#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
      string s;cin>>s;
      for (int i = 0; i < s.length(); i++)
      {
        if (s[0]=='4')
        {
          cout<<"NO"<<endl;
          return;
        }
        if (s[i]=='4' && s[i+1]=='4' && s[i+2]=='4')
        {
          cout<<"NO";
          return;
        }else if (s[i]!='1' && s[i]!='4')
        {
          cout<<"NO";
          return;
        }
      }

      cout<<"YES";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Solution s;
        s.solve();

    return 0;
}