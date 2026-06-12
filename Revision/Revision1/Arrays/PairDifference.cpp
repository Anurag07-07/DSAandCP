#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


class Solution {
  public:
    bool findPairBrute(vector<int> &arr, int x) {
        // code here
        for (int i = 0; i < arr.size(); i++)
        {
          for (int j = i+1; j < arr.size(); j++)
          {
            if (abs(arr[i]-arr[j])==x)
            {
              return true;
            }
            
          }
          
        }
       return false; 
    }

    int hasPairWithDifference(vector<int>& arr, int N, int x) {
    // write your code here 
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = 1;
        while (i<N && j<N)
        {
          int diff = abs(arr[j]-arr[i]);
          if (diff==x && i!=j)
          {
            return true;
          }else if (diff>x)
          {
            i++;
          }else{
            j++;
          }
          if (i==j)
          {
            j++;
          }
          
        }
        
       return 0;
    }

    
    int hasPairWithDifference(vector<int>& arr, int N, int K) {
      unordered_set<int> s;
      for(int x:arr){
        int target = x;
        while (s.find(x-K)!=s.end() || s.find(x+K)!=s.end())
        {
          return true;
        }
        s.insert(x);
      }

      return false;
    }

    
};

int main() {
    vector<int> edges = {
      90,70,20,80,50
    };

    int target = 45;

    Solution sol;
    int ans = sol.hasPairWithDifference(edges,edges.size(),target);
    cout<<ans<<endl;
    cout << endl;

    return 0;
}