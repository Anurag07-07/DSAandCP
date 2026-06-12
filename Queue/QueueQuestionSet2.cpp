#include<bits/stdc++.h>
using namespace std;
void display1(queue<int> q){
  while (!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }

  cout<<endl;
}

int display2(queue<int> q){
  while (!q.empty())
  {
    if(q.front()<0)
    return q.front();
    q.pop();
  }
  return 0;
}

void PrintWindowK(vector<int> nums,int K){
  queue<int> q;
  for(int i = 0;i<K-1;i++)
  q.push(nums[i]);
  
  for (int i = K-1; i < nums.size(); i++)
  {
    q.push(nums[i]);
    display1(q);
    q.pop();
  }
  
}

void PrintMinimumBrute(vector<int> nums,int K){
  queue<int> q;
  for(int i = 0;i<K-1;i++)
  q.push(nums[i]);

  vector<int> ans;
  
  for (int i = K-1; i < nums.size(); i++)
  {
    q.push(nums[i]);
    ans.push_back(display2(q));
    q.pop();
  }
  
}

vector<int> PrintMinimumOptimal(vector<int> nums,int K){
  queue<int> q;
  for(int i = 0;i<K-1;i++)
  if(nums[i]<0)
  q.push(nums[i]);

  vector<int> ans;
  
  for (int i = K-1; i < nums.size(); i++)
  {
    if(nums[i]<0)
    q.push(nums[i]);
    if (q.empty())
    {
      ans.push_back(0);
    }else{
      if(q.front()<=i-K){
        q.pop();
       }
      if (q.empty())
      {
        ans.push_back(0);
      }else{
        ans.push_back(nums[q.front()]);
      }
      
    }
  }
  return ans;  
}

class Solution { 
  public:  
  string solve(string A){
  string B = "";
  vector<int> repeated(26,0);
  queue<int> q;

  for (int i = 0; i < A.size(); i++)
  {
    if (repeated[A[i]-'a']>=1)
    {
      repeated[A[i]-'a']++;
      while (!q.empty() && repeated[A[i]-'a']>1)
      {
        q.pop();
      }

      if (q.empty())
      {
        B+="#";
      }else{
        B+=q.front();
      }
      
      
    }else{
      repeated[A[i]-'a']++;
      q.push(A[i]);
      while (!q.empty() && repeated[A[i]-'a']>1)
      {
        q.pop();
      }
      B+=q.front();
    }
    
  }
  return B;
}
};
int main(int argc, char const *argv[])
{
  vector<int> nums{3,6,2,7,8,11};
  PrintWindowK(nums,3);
  return 0;
}
