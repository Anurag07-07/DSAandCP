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

        int val = n;
        //Create a Fiboncci array
        vector<int> fibo;
        int n1 = 0;
        int n2 = 1;
        fibo.push_back(n1);
        fibo.push_back(n2);
        while (n2<n)
        {
          int n3 = n1+n2;
          if (n3<n)
          {
            fibo.push_back(n3);
          }
          
          n1 = n2;
          n2 = n3;
        }

        int j = fibo.size()-1;
        vector<int> ans;
        while (j>=1)
        {
          if(fibo[j]<=n)
          {
            ans.push_back(fibo[j]);
            n = n-fibo[j];
          }else{
            j--;
          }
        }
        
        if (val==0)
        {
          cout<<"0 0 0";
          return;
        }

        if (val==1)
        {
          cout<<"0 0 1";
          return;
        }


        
        if (ans.size()>3)
        {
          cout<<"I'm too stupid to solve this problem";
          return;
        }else{
          if (ans.size()==2)
          {
            for (int i = 0; i < ans.size(); i++)
            {
              cout<<ans[i]<<" ";
            }
            cout<<"0"<<endl;
          }else{
            for(int x:ans){
              cout<<x<<" ";
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