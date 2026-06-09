#include<bits/stdc++.h>
using namespace std;

stack<int> InsertatBottom(stack<int> st,int x){
  stack<int> temp;
  while (!st.empty())
  {
    temp.push(st.top());
    st.pop();
  }
  
  st.push(x);
  
  while (!temp.empty())
  {
    st.push(temp.top());
    temp.pop();
  }

  return st;

}
void Reverse(vector<char> nums){
  stack<char> st;
  for (int i = 0; i < nums.size(); i++)
  {
    st.push(nums[i]);
  }
  
  int  i = 0;
  while (!st.empty())
  {
    nums[i++] = st.top();

    st.pop();
  }
  
  for(char x:nums){
    cout<<x<<" ";
  }
}

vector<int> MakeArrayBeautiful(vector<int> nums){
  stack<int> neigh;
  for (int i = 0; i < nums.size(); i++)
  {
    if (neigh.empty())
    {
      neigh.push(nums[i]);
    }else if (nums[i]>=0)
    {
      if (neigh.top()>=0)
      {
        neigh.push(nums[i]);
      }else{
        neigh.pop();
      }
    }else{
      if (neigh.top()<0)
      {
        neigh.push(nums[i]);
      }else{
        neigh.pop();
      }
    }
    
  }

  vector<int> ans;
  while (!neigh.empty())
  {
    ans.push_back(neigh.top());
    neigh.pop();
  }

  reverse(ans.begin(),ans.end());
  return ans;
  
}

int StringManipulation(vector<string> nums){
  stack<string> adj;
  for (int i = 0; i < nums.size(); i++)
  {
    if (adj.empty())
    {
      adj.push(nums[i]);
    }else if (adj.top()==nums[i])
    {
      adj.pop();
    }else{
      adj.push(nums[i]);
    }
  }

  return adj.size();
}

string ValidParen(string s){
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
   if (s[i]=='(')
    {
      st.push(s[i]);
    }else{
      if (st.top()=='(')
      {
        st.pop();
      }else if (s.empty())
      {
        return "Not Valid";
      }
    }
  }

  return s.empty() ? "Valid" : "Not Valid";  
}

bool validParentheses(string s){
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    //Opening
    if (s[i]=='(' || s[i]=='['|| s[i]=='{')
    {
      st.push(s[i]);
    }else
    {
      if (st.empty())
      {
        return 0;
      }
      else if (s[i]==')')
      {
        if (st.top()!='(')
        {
          return 0;
        }else{
          st.pop();
        }
      }
      else if (s[i]=='}')
      {
        if (st.top()!='{')
        {
          return 0;
        }else{
          st.pop();
        }
      }
      else if (s[i]==']')
      {
        if (st.top()!='[')
        {
          return 0;
        }else{
          st.pop();
        }
      }
    }
  }
  return s.empty();
}

vector<int> PrintBracketNumber(string s){
  int count = 0;
  stack<char> st;
  vector<int> ans;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i]=='(')
    {
      count++;
      st.push(count);
      ans.push_back(count);
    }else{
      ans.push_back(st.top());
      st.pop();
    }
    
  }

  return ans;
  
}