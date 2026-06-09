// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
      
      stack<int> sst;
      
      while (!st.empty())
      {
        sst.push(st.top());
        st.pop();
      }
      
      st.push(x);

      while (!sst.empty())
      {
        st.push(sst.top());
        sst.pop();
      }

      return st;
    }
};