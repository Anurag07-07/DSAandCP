#include<bits/stdc++.h>
using namespace std;
int c = 0;

int inversion(vector<int> a,vector<int> b){
  int i = 0;
  int j = 0;
  int count = 0;
  while (i<a.size()&&j<b.size())
  {
    if (a[i]>b[j])
    {
      count+=(a.size()-i);
      j++;
    }else{
      i++;
    }
    
  }
  return count;
}


int reversePairs(vector<int>& a,vector<int>& b){
  int i = 0;
  int j = 0;
  int count = 0;
  while (i<a.size()&&j<b.size())
  {
    if (a[i]>2LL*b[j])
    {
      count+=(a.size()-i);
      j++;
    }else{
      i++;
    }
    
  }
  return count;
}


void Merge(vector<int>& a,vector<int>& b,vector<int>& res){
  int i = 0;
  int j = 0;
  int k = 0;
  while (i<a.size()&&j<b.size())
  {
    if (a[i]<=b[j])
    {
      res[k++] = a[i++];
    }else{
      res[k++] = b[j++];
    }
    
  }

  if (i==a.size())
  {
    while (j<b.size())
    {
      res[k++] = b[j++];
    }
    
  }

  if (j==b.size())
  {
    while (i<a.size())
    {
      res[k++] = a[i++];
    }
  }
}



void MergeSort(vector<int>& arr){
  int n = arr.size();
  if (n==1)
  {
    return;
  }

  int n1 = n/2;
  int n2 = n-n1;

  //Create the vector
  vector<int> a(n1),b(n2);
  for (int i = 0; i < n1; i++)
  {
    a[i] = arr[i];
  }

  for (int i = 0; i < n2; i++)
  {
    b[i] = arr[i+n1];
  }
  
  MergeSort(a);
  MergeSort(b);
  c+=reversePairs(a,b);
  Merge(a,b,arr);
  a.clear();
  b.clear();
}

int main(int argc, char const *argv[])
{
  int n;cin>>n;
  vector<int> arr(n);

  for(auto &i:arr){
    cin>>i;
  }

  for(int x:arr){
    cout<<x<<" ";
  }
  cout<<endl;

  MergeSort(arr);
  
  for(int x:arr){
    cout<<x<<" ";
  }

  cout<<endl;
  cout<<"The Count of Reverse Pairs "<<c<<endl;

  return 0;
}
