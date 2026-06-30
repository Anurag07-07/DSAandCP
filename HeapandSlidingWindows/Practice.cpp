#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& arr,int size,int index){
  int largest = index;
  int left = 2*index+1;
  int right = 2*index+2;

  if (left<size && arr[left]>arr[largest])
  {
    largest = left;
  }

  if (right<size && arr[right]>arr[largest])
  {
    largest = right;
  }

  if (largest!=index)
  {
    swap(arr[largest],arr[index]);
    Heapify(arr,size,largest);
  }
}

void Insert(vector<int>& arr,int value){
  arr.push_back(value);
  int og_index = arr.size()-1;

  int i = og_index;
  while (i>0)
  {
    int parent = (i-1)/2;
    if (i<arr.size() && arr[i]>arr[parent])
    {
      swap(arr[i],arr[parent]);
      i = parent;
    }else{
      break;
    }
  }
}

void buildHeap(vector<int>& arr){
  for (int i = (arr.size()/2)-1 ; i >= 0; i--)
  {
    Heapify(arr,arr.size(),i);
  }
}

void Print(vector<int>& arr){
  for (int i = 0; i < arr.size(); i++)
  {
    cout<<arr[i]<<" ";
  }
}

void Delete(vector<int>& arr){
  int size = arr.size();
  arr[0] = arr[size-1];
  arr.pop_back();

  int index = 0;
  while (true)
  {
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if (left<size && arr[left]>arr[largest])
    {
      largest = left;
    }

    if (right<size && arr[right]>arr[largest])
    {
      largest = right;
    }

    if (largest!=index)
    {
      swap(arr[largest],arr[index]);
      index = largest;
    }else{
      break;
    }
  }
}

int main()
{
  vector<int> arr{1,2,3,4,5};
  buildHeap(arr);
  Insert(arr,6);
  cout<<endl;
  Delete(arr);
  Print(arr);
  return 0;
}