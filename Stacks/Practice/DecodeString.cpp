#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
  private:
  stack<pair<int,int>> st;
  int index;
    StockSpanner() {
        index = 0; 
    }
    
    int next(int price) {
      while (!st.empty() && st.top().first<=price)
      {
        st.pop();
      }

      int span;

      if (st.empty())
      {
        span =  index+1;
      }else{
        span = index-st.top().second;
      }
      
      st.push(make_pair(price,index));
      index++;

      return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
     int count = 0;
     int open = 0; 
     for (int i = 0; i < s.length(); i++)
     {
      if (s[i]=='(')
      {
        open++;
      }else if (s[i]==')' && open>0)
      {
        open--;
      }else if (s[i]==')' && open==0)
      {
        count++;
      }
     }
     return count+open;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
     vector<int> newArr;
     for(int i = 1;i<=2;i++){
      for(int x:nums){
        newArr.push_back(x);
      }
     }

     int n = newArr.size();
     vector<int> ans(n,-1);
     stack<int> st;
     for (int i = n-1; i >=0 ; i--)
     {
      while (!st.empty() && st.top()<=newArr[i])
      {
        st.pop();
      }

      if (st.empty())
      {
        ans[i] = -1;
      }else{
        ans[i] = st.top();
      }

      st.push(newArr[i]);
     }

      ans.resize(nums.size()); 
     return ans;
    }

    int minAddToMakeValid(string s) {
      stack<int> st;
      for(char c:s){
        if (c=='(')
        {
          st.push(c);
        }else{
          if (!st.empty() && st.top()=='(')
          {
            st.pop();
          }else{
            st.push(c);
          }
          
        }
        
      }

      return st.size();
    }

    string decodeString(string s) {
      int number = 0;
      string currentString = "";
      stack<string> ch;
      stack<int> num;
      for(char c:s){
        //If i see The Number
        if (isdigit(c))
        {
          number = number*10 + (c-'0');
        }else if (c=='[')
        {
          ch.push(currentString);
          num.push(number);
          currentString="";
          number = 0;
        }else if (c==']')
        {
          //Take the Top string as i want to combine it in the front
          string prev = ch.top(); ch.pop();
          //Find How Many Time We have to Repeat The Number
          int currnum =  num.top();
          num.pop();
          string ans = "";
          for (int i = 0; i < currnum; i++)
          {
            ans+=currentString;
          }

          currentString = prev+ans;
          
        }else{
          currentString+=c;
        }
      }

      return currentString;
    }
};


int main(int argc, char const *argv[])
{
  string s;cin>>s;
  Solution st;
  st.decodeString(s);
  return 0;
}
