#include<bits/stdc++.h>
using namespace std;

//MaxHeap to Sorted Array

void Heapify(int arr[],int index,int n){
  int largest = index;
  int left = 2*index+1;
  int right = 2*index+2;

  if (left<n && arr[left]>arr[largest])
  {
    largest = left;
  }

  if (right<n && arr[right]>arr[largest])
  {
    largest = right;
  }

  if (largest!=index)
  {
    swap(arr[largest],arr[index]);
    Heapify(arr,largest,n);
  }
  
}

void BuildMaxHeap(int arr[],int n){
  for (int i = n/2-1; i >= 0; i--)
  {
    Heapify(arr,i,n);
  }
  
}

void printHeap(int arr[],int n){
  for (int i = 0; i < n; i++)
  {
    cout<< arr[i]<<" ";
  }
  cout<<endl;
}

void sortArray(int arr[],int n){
  for (int i = n-1; i >= 0; i--)
  {
    swap(arr[i],arr[0]);
    Heapify(arr,0,i);
  }
}

int main()
{
  // int arr[] = {1,2,3,10,5,6,7,9};
  // int n  = sizeof(arr)/sizeof(arr[0]);
  // BuildMaxHeap(arr,n); 
  // sortArray(arr,n);
  // printHeap(arr,n);
  // cout<<endl;

  // priority_queue<int> p; //Max heap
  priority_queue<int ,vector<int>,greater<int>>p; //Min Heap
  p.push(10);
  p.push(20);
  p.push(11);
  p.push(18);
  p.push(15);

  //Delete 
  p.pop();
  cout<<p.top()<<endl;

  //Size
  cout<<p.size()<<endl;

  while (!p.empty())
  {
    cout<<p.top()<<" ";
    p.pop(); 
  }
  
  return 0;
}
