#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateBrute(int numRows) {
        vector<vector<int>> ans;
        if (numRows==1) {
            ans.push_back({1});
            return ans;
        }

        ans.push_back({1});
        ans.push_back({1,1});

        for (int i = 2;i<numRows;i++) {
            //Create New Array with +1 size of previous Array
            int new_size = ans[i-1].size();
            vector<int> temp(new_size+1,1);
            for (int j = 1; j < new_size; ++j) {
                 temp[j] =  ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution s;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ans = s.generate(n);
        for (vector<int> x:ans) {
            for (int y:x) {
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
