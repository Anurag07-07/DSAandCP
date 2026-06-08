#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n,k;cin>>n>>k;
  vector<int> nums(n,0);
  vector<int> sleep(n,0);
  for(auto &i:nums)cin>>i;
  for(auto &i:sleep)cin>>i;

  //Sliding window to Find The Maxium Value with Range and starting index
  int maxSum = 0;
  int index = -1;
  int sum = 0;
  for (int i = 0; i < k; i++)
  {
    if (!sleep[i])
    {
      sum += nums[i];
    }
    
  }

  maxSum = max(sum,maxSum);
  
  for (int i = k; i < n; i++)
  {
    if (!sleep[i-k])
    {
      sum -= nums[i-k];
    }
    
    if (!sleep[i])
    {
      sum += nums[i];
    }

    if (sum>maxSum)
    {
        maxSum = sum;
    }
  }

  int totalSum = 0;
  
  for (int i = 0; i < sleep.size(); i++)
  {
    if (sleep[i]==1)
    {
      totalSum += nums[i];
    }
    
  }
  
  
  cout<<maxSum+totalSum<<endl;
  
  return 0;
}
