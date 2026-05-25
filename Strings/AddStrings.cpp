//
// Created by anura on 25-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();

        int i = n1-1;
        int j = n2-1;
        int carry = 0;
        vector<int> ans;

        while (i>=0 && j>=0) {
            //Take char Character
            int last1 = num1[i]-'0';
            int last2 = num2[j]-'0';
            //Add Them along with carry
            int value = last1+last2+carry;
            //Store the value
            int value_to_preserve = value%10;
            //Pass the Carry
            carry = value/10;
            ans.push_back(value_to_preserve);
            i--;
            j--;
        }

        //If num1 is left
        while (i>=0) {
            //Take char Character
            int last1 = num1[i]-'0';
            //Add Them along with carry
            int value = last1+carry;
            //Store the value
            int value_to_preserve = value%10;
            //Pass the Carry
            carry = value/10;
            ans.push_back(value_to_preserve);
            i--;
        }

        //If num2 is left
        while (j>=0) {
            //Take char Character
            int last2 = num2[j]-'0';
            //Add Them along with carry
            int value = last2+carry;
            //Store the value
            int value_to_preserve = value%10;
            //Pass the Carry
            carry = value/10;
            ans.push_back(value_to_preserve);
            j--;
        }

        if(carry){
            ans.push_back(carry);
        }

        reverse(ans.begin(),ans.end());

        //Store it into the string
        string res;
        for (int i = 0; i < ans.size(); ++i) {
            res+=to_string(ans[i]);
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout<<s.addStrings("123","11");
}
