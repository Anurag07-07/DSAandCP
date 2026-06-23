#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
          if (st.empty())
          {
            st.push(s[i]);
          }else{
            if (st.top()==s[i])
            {
              st.pop();
            }else{
              st.push(s[i]);
            }
          }
        }
      
        string ans = "";
        while (!st.empty())
        {
          ans+=st.top();
          st.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
  string s;cin>>s;
  Solution st;
  st.removeDuplicates(s);
  return 0;
}
