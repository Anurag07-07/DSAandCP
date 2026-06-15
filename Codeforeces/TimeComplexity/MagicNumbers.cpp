#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {
      string s;cin>>s;
      //Magic Number
      bool flag = true;
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i]='1' && s[i+1]=='4' && s[i+2]=='4')
        {
          flag = true;
        }else if (s[i]='1' && s[i+1]=='4')
        {
          flag = true;
        }else if (s[i]=='1')
        {
          flag = true;
        }else{
          flag = false;
        }
      }
      
      if (flag==false)
      {
        cout<<"NO"<<endl;
        return;
      }

      
      cout<<"YES"<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Solution s;
        s.solve();

    return 0;
}