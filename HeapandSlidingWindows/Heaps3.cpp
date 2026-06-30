#include<bits/stdc++.h>
using namespace std;

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

void Height(){
  vector<int> arr{1,4,5,4,6,5,5,6,4};
  int height = 0;
  int i = arr.size()-1;
  while (true)
  {
    if (i==0)
    {
      break;
    }
    i=(i-1)/2;
    height++;
  }
  
  cout<<height+1<<endl;
}

// void MinimumCostofRopes(){
//   vector<int> arr{4,2,7,6,9};
//   priority_queue<long long,vector<long,long>,greater<int>> min_heap;

//   int n = arr.size();

//   for (long long i = 0; i < n; i++)
//     min_heap.push(arr[i]);
  
//   long long cost = 0;
  
//   while (min_heap.size()>1)
//   {
//     long long rope = min_heap.top();
//     min_heap.pop();
//     rope+=min_heap.top();
//     min_heap.pop();
//     cost+=rope;
//     min_heap.push(rope);
//   }
  
//   cout<<cost<<endl;
// }

//Magician and Chocolates
//Maximum chocolate you eat in given amount of time
//After eating half number of chocolate again get filled 
// 2 4 8 6 10

void MaximumChocolate(){
  vector<int> choco{2,4,8,6,10};
  int A = 5;
  buildHeap(choco);
  long long count = 0;
  for (int i = 0; i < A; i++)
  {
    //Find the Maximum
    int maxi = choco[0];
    count+=maxi;
    //Delete the Maximum
    Delete(choco);
    //Half the Maximum
    int half = maxi/2;
    //Insert the half
    Insert(choco,half);
  }
  cout<<(count)%100000000007<<endl;

  Print(choco);
  //Time Complexity = A*log2N
  // Space  O(1)


  //Way 2

  priority_queue<int> p;
  for (int i = 0; i < choco.size(); i++)
  
  p.push(choco[i]);

  int a = 0;

  long long chocomax = 0;
  while (a&&!p.empty())
  {
    chocomax+=p.top();
    if (p.top()/2)
    {
      p.push(p.top()/2);
    }

    p.pop();
    a--;
  }
  
  cout<<chocomax%100000000007<<endl;
}

// Last Stone Weight 
//When two stones collide the one with greater weight will destroy the other 
//Retuen the last stone weight
//Take the stone with largest weight

void LargestWeight(){
  // vector<int> stones{2,7,4,1,8,1};
  vector<int> stones{2,2};
  buildHeap(stones);

  while (stones.size()>0)
  {
    //Take two Stones 
    int stone1 = stones[0];
    int stone2 = stones[1];
    Delete(stones);
    Delete(stones);
    int weight = abs(stone1-stone2);
    if (weight)
    {
      Insert(stones,weight);
    }
  }


  if (stones.empty())
  {
    cout<<0<<endl;
  }

  cout<<stones[0]<<endl;  

  //Way 2
  // priority_queue<int> p;
  // for (int i = 0; i < stones.size(); i++)
  // {
  //   p.push(stones[i]);
  // }
  
  // while (p.size()>1)
  // {
  //   int weight = p.top();
  //   p.pop();
  //   weight-=p.top();
  //   p.pop();
  //   if (weight)
  //   {
  //     p.push(weight);
  //   }
    
  // }
  
  // return p.empty() ? 0 :p.top();
}

//Profit Maximization 
void ProfitMaximization(){
  vector<int> profit{6,4,2,3};
  int B = 5;
  // buildHeap(profit);
  // int top = 0;
  // for (int i = 0; i < B; i++)
  // {
  //   //Find Greatest
  //   int t = profit[0];
  //   top += t;
  //   //Delete Greatest
  //   Delete(profit);
  //   //Decrease the Value and Insert it
  //   t--;
  //   //Insert it
  //   Insert(profit,t);
  // }

  // cout<<top<<endl;
  

  //Way 2
  int sum = 0;
  priority_queue<int> p;
  for (int i = 0; i < profit.size(); i++)
    p.push(profit[i]);

  //Sell the Ticket
  while (B&&!p.empty())
  {
    sum += p.top();
    if (p.top()-1)
    {
      p.push(p.top()-1);
    }
    p.pop();
    B--;
  }
    
  cout<<sum<<endl;
}

int main()
{
  // Height();
  // MaximumChocolate();
  LargestWeight();
  // ProfitMaximization();
  return 0;
}

// Time Comp = log2N
// Space Comp = 1

