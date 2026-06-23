#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    void solve1() {
        int n;
        cin >> n;

        vector<string> a(n);
        for (auto &x : a) cin >> x;
        int i = 0,j = n-1;
        while (i<j)
        {
          swap(a[i],a[j]);
          i++;
          j--;
        }


        for(string x:a){
          cout<<x<<" ";
        }

        cout<<endl;
        
    }

    void solve2() {
        int n;
        cin >> n;

        vector<string> a(n);
        for (auto &x : a) cin >> x;
        int i = 0;
        stack<string> st;
        while (i<n)
        {
          st.push(a[i]);
          i++;
        }

        while (!st.empty())
        {
          cout<<st.top()<<" ";
          st.pop();
        }
        
        cout<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    Solution s;
    while (t--) {
        s.solve1();
    }

    return 0;
}