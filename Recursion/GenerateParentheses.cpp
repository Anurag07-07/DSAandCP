//
// Created by anura on 11-05-2026.
//
#include <bits/stdc++.h>
using namespace std;


void Generate(int left,int right,int n,string &temp,vector<string> &ans) {
    // What i see is left + right is equal 2*n
    // Right always comes after left
    // if right count is greater than left it goes wrong

    //Base Case
    if (left+right==2*n) {
        ans.push_back(temp);
        return;
    }

    //Case 1 when left is put
    //When Left count is less than n
    if (left<n) {
        temp.push_back('(');
        //Increase the left Count
        Generate(left+1,right,n,temp,ans);
        //To Reduce the Space Complexity
        temp.pop_back();
    }

    //Case 2 When right will be added
    if (left>right) {
        temp.push_back(')');
        Generate(left,right+1,n,temp,ans);
        temp.pop_back();
    }
}



int main(int argc, char *argv[]) {
    int n;cin>>n;
    string temp;
    vector<string> ans;
    Generate(0,0,n,temp,ans);

    for (auto s:ans) {
        for (auto x:s) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
