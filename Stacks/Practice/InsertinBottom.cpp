#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve1(stack<int> st,int x) {
        // logic here
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
        
        
        while (!st.empty())
        {
          cout<<st.top()<<" ";
          st.pop();
        }
        
    }

    void solve2(stack<int>& st,int x) {
        // logic here
        if (st.empty())
        {
          st.push(x);
          return;
        }

        int topElement = st.top();
        st.pop();

        solve2(st,x);

        st.push(topElement);
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    Solution s;
      s.solve2(st,89);

      while (!st.empty())
      {
        cout<<st.top()<<" ";
        st.pop();
      }
      

    return 0;
}