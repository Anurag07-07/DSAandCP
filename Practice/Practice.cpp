#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void EvenOdd() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        vector<int> ans;
        for(int x:a){
          if(x%2==0){
            ans.push_back(x);
          }
        }
        
        for(int x:a){
          if (x%2!=0)
          {
            ans.push_back(x);
          }
        }

        for(int x:ans){
          cout<<x<<" ";
        }
        
        cout<<endl;
    }

    void EvenOddOpt() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int i = 0;
        int j = n-1;
        while (i<j)
        {
          while(i<n && a[i]%2==0)i++;
          while(j>=0 && a[j]%2!=0)j--;
          if (i<j)
          {
            swap(a[i],a[j]);
            i++;j--;
          }
          
        }

        for(int x:a){
          cout<<x<<" ";
        }

        cout<<endl;
        
    }

    void EvenOddMoreOpt() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int i = 0;
        int j = n-1;
        while (i<j)
        {
          if (a[i]%2==0)i++;
          else if(a[j]%2!=0)j--;
          else{
            swap(a[i],a[j]);
            i++;
            j--;
          }
        }

        for(int x:a){
          cout<<x<<" ";
        }

        cout<<endl;
        
    }

    vector<int> TwoSumBrute() {
        int n;
        cin >> n;

        int target;cin>>target;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        for (int i = 0; i <= n-2; i++)
        {
          for (int j = i+1; j <=n-1; j++)
          {
            if (a[i]+a[j]==target)
            {
              return {i,j};
            }
            
          }
          
        }

        return {0};
        
    }

    vector<int> TwoSumOptimal() {
        int n;
        cin >> n;

        int target;cin>>target;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int i = 0;
        int j = n-1;
        int sum;
        while (i<j)
        {
          sum = a[i]+a[j];
          if (sum==target)
          {
            return {i+1,j+1};
          }else if (sum>target)
          {
            j--;
          }else{
            i++;
          }
        }
        
        return {0};
        
    }

    bool PairDifferenceBrute() {
        int n;
        cin >> n;

        int target;cin>>target;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        if (target<0)
        {
          target = -1*target;
        }
        
        for (int i = 0; i <= n-2; i++)
        {
          for (int j = i+1; j <= n-1; j++)
          {
            if (abs(a[i]-a[j])==target)
            {
              return true;
            }
            
          }
          
        }
        return false;
    }

    bool PairDifferenceBetter() {
        int n;
        cin >> n;

        int target;cin>>target;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(),a.end());
        if (target<0)
        {
          target = -1*target;
        }
        int i = 0;
        int j = 1; 
        int diff;       
        while (j<n)
        {
          diff = a[j]-a[i];
          if (diff==target)
          {
            return true;
          }else if (diff>target)
          {
            i++;
          }else{
            j++;
          }
          if (i==j)
          {
            j = i+1;
          }
          
        }
        return false;
    }

    bool PairDifferenceOpt() {
        int n;
        cin >> n;

        int target;cin>>target;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        unordered_set<int> s;

        for (int i = 0; i < n; i++)
        {
          if (s.count(a[i]-target) || s.count(a[i]+target))
          {
            return true;
          }
          s.insert(a[i]);
        }

        return false;
    }

};

int main() {
    int t;
    cin >> t;

    Solution s;
    while (t--) {
        bool ans = s.PairDifferenceBetter();
          cout<<ans<<endl;
    }

    return 0;
}