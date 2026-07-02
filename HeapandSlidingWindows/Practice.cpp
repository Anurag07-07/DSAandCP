#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int>& nums,int n,int index){
  int largest = index;
  int left = 2*index+1;
  int right = 2*index+2;

  if (left<n && nums[left]>nums[largest])
  {
    largest = left;
  }

  if (right<n && nums[right]>nums[largest])
  {
    largest = right;
  }
  
  if (largest!=index)
  {
    swap(nums[largest],nums[index]);
    Heapify(nums,n,largest);
  }
}

void buildHeap(vector<int>& nums){
  int n = nums.size();
  for (int i = (n/2) - 1; i >= 0; i--)
  {
    Heapify(nums,n,i);
  }
}

void Insert(vector<int>& nums,int element){
  nums.push_back(element);
  int index = nums.size()-1;
  while (index>0)
  {
    int parent = (index-1)/2;
    if (nums[parent]<nums[index])
    {
      swap(nums[parent],nums[index]);
      index = parent;
    }else{
      break;
    }
  }
}

void Delete(vector<int>& nums){
  int elem_index = nums.size()-1;
  nums[0] = nums[elem_index];
  nums.pop_back();
  int index = 0;
  while (true)
  {
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if (left<elem_index && nums[left]>nums[largest])
    {
      largest = left;
    }

    if (right<elem_index && nums[right]>nums[largest])
    {
      largest = right;
    }

    if (largest!=index)
    {
      swap(nums[index],nums[largest]);
      index = largest;
    }else{
      break;
    }
  } 
}

void Print(vector<int>& nums){
  for (int i = 0; i < nums.size(); i++)
    cout<<nums[i]<<" ";

  cout<<endl;  
}

void HeapSort(vector<int>& nums){
  //Create a Max Heap
  buildHeap(nums);
  
  int n = nums.size();
  //Now swap the first element with last element and again create a max heap until we not get a sorted array
  
  for (int i = n - 1; i >= 0; i--)
  {
    swap(nums[0],nums[i]);
    Heapify(nums,i,0);
  }
}

int main()
{
  vector<int> nums{1,2,3,4,5,6};
  buildHeap(nums);  
  Print(nums);
  Insert(nums,10);  
  Print(nums);
  Delete(nums);
  Print(nums);
  HeapSort(nums);
  Print(nums);
  return 0;
}
