#include<bits/stdc++.h>
using namespace std;
void BeautifulArray(vector<int>& nums){
  stack<int> st;
  for (int i = 0; i < nums.size(); i++)
  {
    if (st.empty())
    {
      st.push(nums[i]);
    }else{
        int topelem = st.top();
        if ((topelem>=0 && nums[i]<0) || (topelem<0 && nums[i]>=0))
        {
          st.pop();
        }else{
          st.push(nums[i]);
        }
    }
    
  }

  vector<int> ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(),ans.end());
  
  
  for(int x:ans){
    cout<<x<<" ";
  }

}

void BeautifulArraySpaceOptimization(vector<int>& nums){
  vector<int> ans;

  for (int i = 0; i < nums.size(); i++)
  {
    if (ans.empty())
    {
      ans.push_back(nums[i]);
    }else{
      int topelem = ans.back();
      if ((topelem>=0 && nums[i]<0) || (topelem<0 && nums[i]>=0))
      {
        ans.pop_back();
      }else{
        ans.push_back(nums[i]);
      }
    }
    
  }
  

  for(int x:ans){
    cout<<x<<" ";
  }

}

int main(int argc, char const *argv[])
{
  int n;cin>>n;
  vector<int> nums(n,0);
  for(auto &i:nums) cin>>i;
  BeautifulArraySpaceOptimization(nums);
  return 0;
}
