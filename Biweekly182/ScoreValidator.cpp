//
// Created by anura on 09-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int score = 0;
    int counter = 0;
    vector<string> events{"W","W","W","W","W","W","W","W","W","W","W"};

    for (auto x: events) {
        char c = x[0];
        if (x=="W") {
            counter++;
            if (counter==10) {
                break;
            }
        }
        else if (c-'0'>=0 && c-'0'<=6) {
            score+=stoi(x);
        }
        else{
            score+=1;
        }
    }

    // return {score,counter};
    cout<<counter<<" "<<score<<endl;
    return 0;
}
