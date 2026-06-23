#include<bits/stdc++.h>
using namespace std;

bool ValidParenthesis(string s){
  stack<int> st;
  for(char c:s){
    if (c=='(' || c=='{' || c=='[')
    {
      st.push(c);
    }else{
      if (st.empty())
      {
        return false;
      }
      char top = st.top();
      if (c==')' && top=='(' || c=='}' && top=='{' || c==']' && top=='[')
      {
        st.pop();
      }else{
        return false;
      }
    }
    
  }

  return st.empty();
}

int main(int argc, char const *argv[])
{
  string s;cin>>s;
  ValidParenthesis(s);
  return 0;
}
