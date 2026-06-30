#include<bits/stdc++.h>
using namespace std;

class HeapSort{
  public:
  void MaxHeapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left]>arr[largest])
    {
      largest = left;
    }

    if (right<n && arr[right]>arr[largest])
    {
      largest = right;
    }
    
    if (largest!=i)
    {
      swap(arr[largest],arr[i]);
      MaxHeapify(arr,n,largest);
    }
    
  }

  void BuildHeap(int arr[],int n){
    for (int i =(n/2) - 1; i >= 0; i--)
    {
      MaxHeapify(arr,n,i);
    }

    for (int i = n - 1; i > 0; i--)
    {
      swap(arr[0],arr[i]);
      MaxHeapify(arr,i,0);
    }
  }

  void print(int* arr,int n){
    for (int i = 0; i < n; i++)
    {
      cout<<arr[i]<<" ";
    }
    
  }

};

int main(int argc, char const *argv[])
{
  int arr[] = {5,4,6,5,1,2,1,1,8,4,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  HeapSort h;
  h.BuildHeap(arr,n);
  h.print(arr,n);
  return 0;
}
