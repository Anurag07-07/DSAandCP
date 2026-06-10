#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> heights) {
        // code here
        int n = heights.size();
        vector<int> left(n);      
        vector<int> right(n);

        stack<int> st;

        
        for (int i = 0; i < n; i++)
        {
          while (!st.empty() && heights[st.top()]>heights[i])
          {
            right[st.top()] = i;
            st.pop();
          }
          st.push(i);
          
          //Empty The Stack
          
          while (!st.empty())
          {
            right[st.top()] = n;
            st.pop();
          }
          
        }
        


        for (int i = n-1; i >=0 ; i--)
        {
          while (!st.empty() && heights[st.top()]>heights[i])
          {
            left[st.top()] = i;
            st.pop();
          }
          st.push(i);
          
          //Empty The Stack
          
          while (!st.empty())
          {
            left[st.top()] = -1;
            st.pop();
          }
          
        }


        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
          ans = max(ans,heights[i]*(right[i]-left[i]-1));
        }
        
        return ans;
    }
};







int main(int argc, char const *argv[])
{
  return 0;
}
