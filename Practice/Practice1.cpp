#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    bool PARTIONBRUTE() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        for (int i = 0; i < n-1; i++)
        {
          int sum1 = 0;int sum2= 0;
          for (int j = 0; j <= i; j++)
          {
            sum1+=a[j];
          }

          for (int j = i+1; j < n; j++)
          {
            sum2+=a[j];
          }
          
          if (sum1==sum2)
          {
            return true;
          }
          
        }
        return false;
    }

    bool PARTIONBOPTIMAL() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int totalSum = accumulate(a.begin(),a.end(),0);
        long long leftsum = 0;
        for(int x:a){
          leftsum += x;
          if (2*leftsum == totalSum)
          {
            return true;
          }
          
        }
        return false;
    }

    bool PARTIONTwoPointer() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        // logic here
        int i = 0;int j = n-1;
        int leftsum = a[i];
        int rightsum = a[j];
        while (i<j)
        {
          if (leftsum<rightsum)
          {
            i++;
            leftsum+=a[i];
          }else{
            j--;
            rightsum+=a[j];
          }

          if (leftsum==rightsum)
          {
            return true;
          }
          
        }
        
        return false;
    }
    int maxSubArrayBrute(vector<int>& nums) {
      int n = nums.size();
      int maxsum = INT_MIN;
      for (int i = 0; i < n; i++)
      {
        for (int j = i; j < n; j++)
        {
          int sum = 0;
          for (int k = i; k <= j; k++)
          {
            sum += nums[k];
          }
          maxsum = max(maxsum,sum);
        }
        
      }

      return maxsum;
    }

    int maxSubArrayBetter(vector<int>& nums) {
      int n = nums.size();
      vector<int> psum(n,0);
      psum[0] = nums[0];
      for (int i = 1; i < n; i++)
      {
        psum[i] = psum[i-1]+nums[i];
      }
      
      int maxsum = INT_MIN;
      for (int i = 0; i < n; i++)
      {
        for (int j = i; j < n; j++)
        {
          int sum = 0;
          if (i==0)
          {
            sum = psum[j];
          }else{
            sum = psum[j]-psum[i-1];
          }
          
          maxsum = max(maxsum,sum);
        }
        
      }

      return maxsum;
    }

    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      int maxsum =INT_MIN;
      for(int x:nums){
        sum +=x;
        maxsum = max(maxsum,sum);
        if(sum<0) sum = 0;
      }
      return maxsum;
    }

    void maximumDifferenceBrute() {

      int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &x : nums) cin >> x;


      int maxdiff = -1;
      for (int i = 0; i < n-1; i++)
      {
        for (int j = i+1; j < n; j++)
        {
          if (nums[j]>nums[i])
          {
            int diff = nums[j]-nums[i];
            maxdiff = max(maxdiff,diff);
          }
          
        }
        
      }

      cout<<maxdiff<<endl;
    }

    void maximumDifferenceBetter() {

      int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &x : nums) cin >> x;

        vector<int> psum(n,0);
        psum[n-1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
          psum[i] = max(psum[i+1],nums[i+1]);
        }

        int maxdiff = -1;
        for (int i = 0; i < n; i++)
        {
          int diff = psum[i]-nums[i];
          maxdiff = max(maxdiff,diff);
        }
        
        cout<<maxdiff<<endl;  
    }

    void maximumDifferenceOptimal() {

        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &x : nums) cin >> x;

        int rightmax = 0;
        int  maxdiff = -1;

        for (int i = n - 1; i >= 0; i--)
        {
          //Find the diff
          int diff = rightmax-nums[i];
          maxdiff = max(maxdiff,diff);
          rightmax = max(rightmax,nums[i]);
        }

        cout<<maxdiff<<endl;  
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    Solution s;
    while (t--) {
        s.maximumDifferenceOptimal();
    }

    return 0;
}