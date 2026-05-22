//
// Created by anura on 22-05-2026.
//
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {

    int n;cin>>n;
    //How many years
    int years = n/365;
    cout<<years<<" years"<<endl;
    n = n - years*365;
    int month = n /30;
    cout<<month<<" months"<<endl;
    n = n - month*30;
    cout<<n<<" days";
}
