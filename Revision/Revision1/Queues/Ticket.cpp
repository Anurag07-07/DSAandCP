#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int totalTime = 0;
        while (tickets[k]>0)
        {
          for (int i = 0; i < n; i++)
          {
            if (tickets[i]>0)
            {
              tickets[i]--;
              totalTime++;
            }
            
            if (tickets[k]==0)
            {
              return totalTime;
            }
          }
          
        }
        return totalTime;
    }

    int timeRequiredToBuy(vector<int>& tickets, int k) {
      queue<int> q;
      int n = tickets.size();
      for (int i = 0; i < n; i++)
      {
        q.push(i);
      }
      int totalTime= 0;
      
      while (!q.empty())
      {
        int first = q.front();
        q.pop();
        tickets[first]--;
        totalTime++;

        if (first==k && tickets[first]==0)
        {
          return totalTime;
        }

        if(tickets[first]>0){
          q.push(first);
        }
        
      }
      return totalTime;
    }

    int timeRequiredToBuy(vector<int>& tickets, int k) {
      int n = tickets.size();
      int totalTime = 0;
      int maxChance = tickets[k];
      for (int i = 0; i < n; i++)
      {
        if (i<=k)
        {
          totalTime+=min(tickets[i],maxChance);
        }else{
          totalTime+=min(tickets[i],maxChance-1);
        }
      }
      return totalTime;
    }
};

