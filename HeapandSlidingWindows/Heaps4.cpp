#include<bits/stdc++.h>
using namespace std;
void KthSmallest(){
  /*
  
  => Brute Force
  For Duplicate both will consider
  Sort the Array and find the k-1 index elment return it

  Time = O(nlogn)
  Space = O(1) for heap sort O(n) for merge sort

  => Better
  Min Heap
  Delete Root Element K Times

  Time = O(n)+(K*logn) for deleting K-1 Element ro in worst case
  K==N so Time = O(n) +  O(nlogn)
  K==1 so Time = O(n) +  O(logn)
  So Klogn is average complexity
  Space = O(1)


  => Optimal
  Max Heap
  Store K element 
  Traverse the array and check 
  If Current is smaller than largest store it and delete the largest 

  Time = O(K)+O((n-k)*2logK) for insert and Delete 
  */
  vector<int> arr{7,10,4,3,20,15};
  int k = 3;
  int l = 0;
  int r = arr.size()-1;
  
  priority_queue<int> p;
  for (int i = 0; i < k; i++)
  p.push(arr[i]);
  
  for (int i = k; i <=r; i++)
  {
    if (arr[i]<p.top())
    {
      p.pop();
      p.push(arr[i]);
    }
  }
  cout<<p.top()<<endl;
}

void KthLargest(){
  /* 
  Brute 
  Sort the Array Reverse it and Return K-1th Index

  Better
  Max Heap
  Create Max heap
  Delete the Root K times and Return the root
  Time = n+klogn 
  
  Optimal 
  Min Heap
  Store K Element 
  Traverse Over array and Store the Current Element when Top is less than Current Element
  Time O(k)+((n-k)*2logk)
  */
 
 vector<int> arr{6,8,2,10,5,7,4,3};
 priority_queue<int,vector<int>,greater<int>> p;
 int k = 3;
 for (int i = 0; i < k; i++)
  p.push(arr[i]);

  for (int i = k; i < arr.size(); i++)
  {
    if (arr[i]>p.top())
    {
      p.pop();
      p.push(arr[i]);
    }
    
  }

  cout<<p.top()<<endl;
}
void KthLargestElementinaStream(){
    
}

void SumofElementBetweenK1andK2SmallestElement(){
  /*
  Brute 
  Sort the Array and Find the Sum in a range
  from K1-1 to K2-1 index

  //Optimal 
  Max Heap 
  Find The sum of k1 element 
  find the sum of k2-1 element k2 excluded
  //Subtract them
  */
  vector<int> nums{20,8,22,4,12,10,14};
  
  int k2 = 6;
  int k1 = 3;

  priority_queue<long long> p1;
  priority_queue<long long> p2;

  for (long long i = 0; i < k1; i++)
    p1.push(nums[i]);
  for (long long i = 0; i < k2; i++)
    p1.push(nums[i]);
  
  for (long long i = k1; i <=nums.size(); i++)
  {
    if (nums[i]<p1.top())
    {
      p1.pop();
      p1.push(nums[i]);
    }
  }

  for (long long i = k2-1; i <=nums.size(); i++)
  {
    if (nums[i]<p2.top())
    {
      p2.pop();
      p2.push(nums[i]);
    }
  }

  //Find The Sum
  long long sum1 = 0;
  long long sum2 = 0;

  while (!p1.empty())
  {
    sum1+=p1.top();
    p1.pop();
  }

  while (!p2.empty())
  {
    sum1+=p2.top();
    p2.pop();
  }
  

  cout<<sum2-sum1<<endl;
}

int main(int argc, char const *argv[])
{
  KthSmallest();
  KthLargest();
  return 0;
}