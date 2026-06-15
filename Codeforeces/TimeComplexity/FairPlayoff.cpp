#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve() {

        vector<int> a(4);
        for (auto &x : a) cin >> x;

        // logic here
        int maxi = INT_MIN;
        int s_maxi = INT_MIN;

        for (int i = 0; i < a.size(); i++)
        {
          maxi = max(maxi,a[i]);          
        }

        for (int i = 0; i < a.size(); i++)
        {
          if (a[i]>s_maxi && a[i]!=maxi)
          {
            s_maxi = max(s_maxi,a[i]);          
          }
          
        }
        
        
        int first_winner = 0;
        if (a[0]>a[1])
        {
          first_winner = a[0];
        }else{
          first_winner = a[1];
        }
        
        int second_winner = 0;
        if (a[2]>a[3])
        {
          second_winner = a[2];
        }else{
          second_winner = a[3];
        }


        if (first_winner==maxi && second_winner==s_maxi)
        {
          cout<<"YES"<<endl;
        }else if (first_winner==s_maxi && second_winner==maxi)
        {
          cout<<"YES"<<endl;
        }else{
          cout<<"NO"<<endl;
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