#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
  vector<int> maxofMinOptimized(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n+1,0);
    
    //Using Montonic Increasing Stack Calculate the min for stack top element
    for (int i = 0; i <=n; i++)
    {
      while (!st.empty() && nums[st.top()]>=nums[i])
      {
        int curr = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = i;
        int len = right-left-1;
        //Calculate the length for current top and store at the correct position
        ans[len] = max(ans[len],nums[curr]);
      }
      st.push(i);
    }

    //If Stack is not empty
    while (!st.empty())
    {
      int curr = st.top();
      st.pop();
      int left = st.empty() ? -1 :st.top();
      //n because if stack is not empty 
      //it means for top element we cant find the smaller element
      //on right side so we assume that the next smaller we get at index = n
      //Same for left also if no left smaller is there it must present at index -1
      int right = n;
      int len = right-left-1;
      ans[len] = max(ans[len],nums[curr]);
    }

    //Filled the Left Position
    for (int i = n - 1; i >= 0; i--)
    {
      ans[i] = max(ans[i],ans[i+1]);
    }
        
    return vector<int>(ans.begin()+1,ans.end());
    
  }
  vector<int> maxofMinOptimizedOneLoop(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n+1,0);
    for (int i = 0; i <=n; i++)
    {
      //at i == n -1 element is present
      int curr = i==n ? -1 : nums[i];
      while (!st.empty() && nums[st.top()]>curr)
      {
        int top_index = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = i;
        int len = right-left-1;
        //Calculate the length for current top and store at the correct position
        ans[len] = max(ans[len],nums[top_index]);
      }
      st.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    ans[i] = max(ans[i],ans[i+1]);
        
    return vector<int>(ans.begin()+1,ans.end());
  }

  vector<int> maxofMin(vector<int> nums){
    //Find the Left Smaller Index and Right Smaller element Index
    int n = nums.size();
    vector<int> lse(n,0);
    vector<int> rse(n,0);
    stack<int> st;
    

    //Find the Left Smaller Elements Index
    for (int i = 0; i < n; i++)
    {
      //Jab tak bda ya brabar hai element nikal do
      while (!st.empty() && nums[st.top()]>=nums[i])
      {
        st.pop();
      }
      
      if (st.empty())
      {
        lse[i] = -1;
      }else{
        lse[i] = st.top();
      }

      st.push(i);
    }

    //Reuse Stack
    while (!st.empty())
    st.pop();
    
    //Find Right Min Element
    for (int i = n-1; i >=0 ; i--)
    {
      while (!st.empty() && nums[st.top()]>=nums[i])
      {
        st.pop();
      }

      if (st.empty())
      {
        rse[i] = n;
      }else{
        rse[i] = st.top();
      }

      st.push(i);
      
    }

    //Find the Window for Each Element
    vector<int> window_size(n+1,0);
    for (int i = 0; i < nums.size(); i++)
    {
      int len = rse[i]-lse[i]-1;
      window_size[len] = max(window_size[len],nums[i]);
    }

    //Fill the Left places
    for (int i = n-1 ; i >= 1; i--)
    {
      window_size[i] = max(window_size[i],window_size[i+1]);
    }

    return vector<int>(window_size.begin()+1,window_size.end());
  }
};





int main(int argc, char const *argv[])
{
  vector<int> nums{10,20,15,50,10,70,30};
  Solution s;
  vector<int> ans = s.maxofMinOptimizedOneLoop(nums);
  for(int x:ans){
    cout<<x<<" ";
  }
  return 0;
}

