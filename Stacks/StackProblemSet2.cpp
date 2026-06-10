#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterBrute(vector<int> nums){
  int n = nums.size();
  vector<int> ng(n,-1);
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = i+1; j < n; j++)
    {
      if (nums[j]>nums[i])
      {
        ng[i] = nums[j];
        break;
      }
    }
  }
  return ng;
}

vector<int> nextGreaterOptimal(vector<int> nums){

  int n = nums.size();
  vector<int> ng(n,-1);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top()<=nums[i])
    {
      st.pop();
    }

    if (st.empty())
    {
      ng[i] = -1;
    }else{
      ng[i] = st.top();
    }
    
    st.push(nums[i]);
  }
  return ng;
}


class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        int n = arr.size();
        vector<int> ns(n,-1);
        for (int i = n - 1; i >= 0; i--)
        {
          while (!st.empty() && st.top()>=arr[i])
          {
            st.pop();
          }

          if (st.empty())
          {
            ns[i] = -1;
          }else{
            ns[i] = st.top();
          }
          
           st.push(arr[i]);
        }
        
        
        return ns;
    }
};

vector<int> Smallestonleft(int arr[], int n) {
    // code here
    stack<int> st;
    vector<int> ls(n);
    for (int i = 0; i < n; i++)
    {

      while (!st.empty() && st.top()>=arr[i])
      {
        st.pop();
      }
      

      if (st.empty())
      {
        ls[i] = -1;
      }else{
        ls[i] = st.top();
      }
      st.push(arr[i]);
    }
    return ls;
}

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        //Stack to store next bda element ka index jo pehle aa chuka hai
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,1);
        for (int i = 0; i < n; i++)
        {
          //Jab Tak Stack ke index ke elment chote hai current se stack khali karo
          while (!st.empty() && arr[st.top()]<=arr[i])
          {
            st.pop();
          }

          if (st.empty())
          {
            ans[i] = i+1;
          }else{
            ans[i] = i-st.top();
          }
          st.push(i);
        }
        
        return ans;
    }
};

class Solution {
public:
    int largestRectangleAreaBrute(vector<int>& heights) {
      int n = heights.size();
      int max_area = 0;
      int width;
      int area;
      for (int i = 0; i < n; i++)
      {
        int min_height = heights[i];
        for (int j = i; j < n; j++)
        {
          min_height = min(min_height,heights[j]);
          width = j-i+1;
          area = min_height*width;
          max_area = max(max_area,area);
        }
        
      }
     return max_area;       
    }
};

class Solution {
public:
    int largestRectangleAreaOptimal(vector<int>& heights) {
      int n = heights.size();
      stack<int> st;
      int area;
      int max_area = 0;
      int width;
      int height;
      for (int i = 0; i <= n; i++)
      {
        //Find the Current Height of the Building
        int currentHeight = i==n ? 0 : heights[i];
        //Calculate the Area for Each Bigger Height Present in stack 
        //Then store the Element because this is monotonic increasing stack 
        //It will Store element which is greater than previous value
        while (!st.empty() && heights[st.top()]>currentHeight)
        {
          //Calculate the Height 
          height = heights[st.top()];
          st.pop();
          //Calculate Width 
          width = st.empty() ? i : i-st.top()-1;
          area = width*height;
          max_area = max(max_area,area);
        }
        st.push(i);
      }


      return max_area;
      
    }
};

class Solution {
public:
    int largestHistogramArea(vector<int> heights){
      int area;
      int height;
      int width;
      int max_area = 0;
      int n = heights.size();
      stack<int> st;
      for (int i = 0; i <= n; i++)
      {
        int currentHeight = i==n ? 0 : heights[i];
        while (!st.empty() && heights[st.top()]>currentHeight)
        {
          height = heights[st.top()];
          st.pop();

          width = st.empty() ? i : i-st.top()-1;
          area = width*height;
          max_area = max(max_area,area);
        }
        st.push(i);
      }

      return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      if (matrix.empty())
      return 0;
      
      int maxarea = 0;
      int area;
      int rows = matrix.size();
      int cols = matrix[0].size();
      vector<int> base(cols,0);
      for (int i = 0; i < rows; i++)
      {
        for (int j = 0; j < cols; j++)
        {
          if (matrix[i][j]=='1')
          {
            base[j] += 1;
          }else{
            base[j] = 0;
          }
          
        }
        
        area = largestHistogramArea(base);
        maxarea = max(maxarea,area);
      }
      return maxarea;
    }
};
