//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>

//If i want to reach stair 0 there is only 1 way
//If i want to reach stair 1 there is only 1 way
//If i want to reach stair 2 there are 2 way 1+1 or 2
//If i want to reach stair 3 there are 3 way 1+1+1 or 2+1 or 1+2
//If i want to reach stair 4 there are 5 way 1+1+1+1 or 2+2 or 1+2+1 or 2+1+1 or 1+1+2

//If we observe current one is um of previous two


using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        //Base case
        if (n==0 || n==1) {
            return 1;
        }

        return climbStairs(n-1)+climbStairs(n-2);
    }
};

int main(int argc, char *argv[]) {
    int n;cin>>n;
    Solution s;
    cout<<s.climbStairs(n);
}
