#include<bits/stdc++.h>
using namespace std;
vector<int> minimummax(vector<int> nums){
  vector<int> ans(nums.size(),0);
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = 0; j < nums.size()-i; j++)
    {
      int mini = INT_MAX;
      for (int k = j; k < j+i+1; k++)
      {
        mini = min(mini,nums[k]);
      }
      ans[i] = max(mini,ans[i]);
    }
  }
  return ans;    
}


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& nums) {
        //  code here
        int n = nums.size();
        //Find left smallest and Right Smallest for each element
        vector<int> lse(n,0);      
        vector<int> rse(n,0);
        stack<int> st;
        
        //Find the lse
        for (int i = 0; i < n; i++)
        {
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

        //Clean the stack
        while (!st.empty())
        st.pop();
        

        //For Rse
        for (int i = n-1; i >= 0; i--)
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
        
        //Now Find the maximum Window size
        vector<int> max_window(n+1,0);
        int len;
        for (int i = 0; i < nums.size(); i++)
        {
          len = rse[i]-lse[i]-1;
          max_window[len] = max(max_window[len],nums[i]);
        }

        //Backward pass for left element
        for (int i = n-1; i >= 1; i--)
        {
          max_window[i] = max(max_window[i],max_window[i+1]);
        }
        
        //Now Return the Array
        return vector<int>(max_window.begin()+1,max_window.end());
    }
};

class Solution {
  public:
    vector<int> maxOfMinsMoreOptimized(vector<int>& nums) {
        //  code here
        int n = nums.size();
        //Find left smallest and Right Smallest for each element
        stack<int> st;
        vector<int> max_window(n+1,0);
        
        //Find the lse
        for (int i = 0; i <= n; i++)
        {
          while (!st.empty() && nums[st.top()]>=nums[i])
          {
            //Pop out top element
            int curr = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int len = i-left-1;
            max_window[len] = max(max_window[len],nums[curr]);
          }
          st.push(i);
        }
        
        //Clean the stack
        while (!st.empty()){
          int curr = st.top();
          st.pop();
          
          int left = st.empty() ? -1 : st.top();
          int right  = n;
          int len = right-left-1;
          max_window[len] = max(max_window[len],nums[curr]);
        }
        

        //Backward pass for left element
        for (int i = n-1; i >= 1; i--)
        {
          max_window[i] = max(max_window[i],max_window[i+1]);
        }
        
        //Now Return the Array
        return vector<int>(max_window.begin()+1,max_window.end());
    }
};
class Solution{
  int celibrityProbStack(vector<vector<char>>& matrix){
    stack<int> st;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = n-1; i >= 0; i--)
    st.push(i);    
    
    int first;
    int second;
    while (st.size()>1)
    {
      //First Person 
      first = st.top();
      st.pop();
      second = st.top();
      if (matrix[first][second]==1 && matrix[second][first]==0)
      st.push(second);

      if (matrix[first][second]==0 && matrix[second][first]==1)
      st.push(first);
    }

    if (st.empty())
    {
      return -1;
    }
    
    //Verification
    int candidate = st.top();
    st.pop();
    int knows = 0;
    int dontknow = 0;
    for (int i = 0; i < n; i++)
    {
      knows+=matrix[i][candidate];
      dontknow+=matrix[candidate][i];
    }
    return knows==n-1 && dontknow==0 ? candidate : -1;
  }

  int celibrityProbTwoPointer(vector<vector<char>>& matrix){
    int top = 0;
    int down = matrix[0].size()-1;
    while (top<down)
    {
      if (matrix[top][down]==1)
      top++;
      else
      down--;      
    }
    
    //Verification
    int candidate = top; // or down
    for (int i = 0; i < matrix.size(); i++)
    if(matrix[candidate][i]==1 || matrix[i][candidate]==0)
    return -1;

    return candidate;
  }
};


int main(int argc, char const *argv[])
{
  return 0;
}
