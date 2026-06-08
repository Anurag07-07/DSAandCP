#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n;cin>>n;
  while (true)
  {
    if (n)
    {
      cout<<"I hate"<<" ";
      n--;
    }
    if (n==0)
    {
      cout<<"it"<<" ";
      break;
    }else{
      cout<<"that"<<" ";
    }
    
    if (n)
    {
      cout<<"I love"<<" ";
      n--;
    }
    if (n==0)
    {
      cout<<"it"<<" ";
      break;
    }else{
      cout<<"that"<<" ";
    }
  }
  
  return 0;
}
