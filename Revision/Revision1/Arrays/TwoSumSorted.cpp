#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> twoSum(vector<int> numbers, int target) {
      int n = numbers.size();  
        for (int i = 0; i < n; i++)
        {
          for (int j = i+1; j < n; j++)
          {
            if (numbers[i]+numbers[j]==target)
            {
              return {i+1,j+1};
            }
            
          }
          
        }
      return {0,0};  
    }

    vector<int> twoSum(vector<int> numbers, int target) {
      int n = numbers.size();
      int i = 0;
      int j = n-1;
      int sum;
      while (i<j)
      {
        sum = numbers[i]+numbers[j];
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
      return {1,1};
    }
};

int main() {
      vector<int> numbers{2,7,11,15};

    Solution sol;
    vector<int> ans = sol.twoSum(numbers,9);

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}