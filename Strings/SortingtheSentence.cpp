#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
    string s;cin>>s;
    vector<string> ans(10,"");

    int i = 0;
    string temp;
    int count = 0;
    while (i<s.length()) {
        if (s[i]==' ') {
         //Find the Position of string
         int index = temp[temp.size()-1]-'0';
            //Remove the last number from string
            temp.pop_back();
         //Insert the string
         ans[index] = temp;
            //Clear the String
            temp.clear();
            //Increase the Word Count
          count++;
        }else {
            temp+=s[i];
        }
        i++;
    }

    //Do this Again for last word
    //Find the Position of string
    int index = temp[temp.size()-1]-'0';
    //Remove the last number from string
    temp.pop_back();
    //Insert the string
    ans[index] = temp;
    //Clear the String
    temp.clear();
    //Increase the Word Count
    count++;

    //Now create a string
    string res;
    for (int j = 1; j <=count; ++j) {
        res+=ans[j];
        res+=" ";
    }
    //Remove the last space
    res.pop_back();

    cout<<res<<endl;
}