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
/*
  Brute 
  Start from last Index and Run a loop till not get at index zero 
  Take the jump of i-1/2 and increase the count while taking a jump 
  return count+1 

  Time O(logn) Space O(1)

  Optimal
  If n is given height = log(n)+1 for complete binary tree 
  
  Time O(1) space O(1)

*/

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

int MinimumCostofRopes(vector<int>& temp){
  /*
  Brute 
  Recursion + Loop
  Check Every Possiblities 
  Take Two Element sum it up 
  Push all the Other Elment In Temp array 
  Calculate the sum of two and store it inside temp 
  Now call recursion and pass the temp into the recursion and when they recturn some value add with that two element
  and find the minimum till now  
  Time O(2^n)  
  */
 vector<int> arr{4,2,7,6,9};
  int ans = INT_MAX;
  int n = arr.size();
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      vector<int> temp;
      for (int k = 0; k < n; k++)
      {
        if (k!=i && k!=j)
        {
          temp.push_back(arr[k]);
        }
        
      }

      int mergecost = arr[i]+arr[j];
      temp.push_back(mergecost);

      ans = min(ans,mergecost+MinimumCostofRopes(temp));
    }
  }


  cout<<ans<<endl;


  /* 
  Optimization 
  1 3 100 100 
  We are combine the pair and it into the future for maxking the the smallest rope cost
  But If we think 
  If we combine two largesst element it will never reduce my total cost 
  So waht we Observe is take two samllest rope and combine them
  Like 100 + 100 = 200 which contribute in next cost, that make cost larger
  But if we consider 1+3 = 4 it not increases the cost much

  Steps 
  Take Two Samllest Element Add them
  Insert it again into the min heap till one element not left  
  
  Time O(nlogn) or O(n) for building the heap + 2 pop and 1 push O(logn) 
  Space O(n) 
  Min heap because we want two smallest Element from the Array
  */
  

  // priority_queue<long long,vector<long,long>,greater<int>> min_heap;

  // int n = arr.size();

  // for (long long i = 0; i < n; i++)
  //   min_heap.push(arr[i]);
  
  // long long cost = 0;
  
  // while (min_heap.size()>1)
  // {
  //   long long rope = min_heap.top();
  //   min_heap.pop();
  //   rope+=min_heap.top();
  //   min_heap.pop();
  //   cost+=rope;
  //   min_heap.push(rope);
  // }
  
  // cout<<cost<<endl;
}

//Magician and Chocolates
//Maximum chocolate you eat in given amount of time
//After eating half number of chocolate again get filled 
// 2 4 8 6 10

void MaximumChocolate(){
  /*
  Brute 
  Select the Maximum Chocolate and also the index
  Add it into the answer and then at that index put maximum_chocolate/2 chocolate

  Time O(n*k) Space O(1)
  */
 vector<int> choco{2,4,8,6,10};
 int A = 5;
 int ans = 0; 
 while (A--)
 {
  int maxi = INT_MIN;
  int index = -1;
  for (int i = 0; i < choco.size(); i++)
  {
    if (choco[i]>maxi)
    {
      maxi = choco[i];
      index = i;
    }
    
  }

  ans+=maxi;
  choco[index] = maxi/2;
 }
 
 /*
 Optimization 
 Max Heap
 Find the Maximum add it into the answer and divide it by 2 and again store it inside the heap 
 Time O(nlogn) for building heap and Klogn for inserting and poping out Element form the heap
 */


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
//Return the last stone weight
//Take the stone with largest weight

void LargestWeight(){
  /*
  Brute 
  Take the First Largest from the Array 
  Take the Second Largest from the Array
  Delte both of them from array and Find the Difference and store it inside the array
  
  Time O(n)for iteration and O(n) for max second max and delete Total O(n^2)
  Space O(1)
  */
 vector<int> stones{2,7,4,1,8,1};

  int ans = 0;
  while (stones.size() > 1)
    {
        // Find largest stone
        int firstIndex = 0;
        for (int i = 1; i < stones.size(); i++)
        {
            if (stones[i] > stones[firstIndex])
                firstIndex = i;
        }

        int first = stones[firstIndex];
        stones.erase(stones.begin() + firstIndex);

        // Find second largest stone
        int secondIndex = 0;
        for (int i = 1; i < stones.size(); i++)
        {
            if (stones[i] > stones[secondIndex])
                secondIndex = i;
        }

        int second = stones[secondIndex];
        stones.erase(stones.begin() + secondIndex);

        // Insert remaining weight
        if (first != second)
            stones.push_back(first - second);

          
    }
    int ans = stones.empty() ? 0 : stones[0];
    cout<<ans<<endl;

    /*
    Optimization
    Max Heap 
    Take Two Largest Stone Remove Find Difference and Store it Again till Heap not get empty 
    If empty return 0 if stone left return that stone
    Time O(nlogn) Space O(n)
    */

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
  /*
  Brute 
  On Each Iteration Find the maximum add it into profit and 
  Subtract the Value by 1 
  Time O(n^2) Space O(1)
  */

  vector<int> profit{6,4,2,3};
  int B = 5;

  int ans = 0;
  while (B--)
  {
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < profit.size(); i++)
    {
      if (profit[i]>maxi)
      {
        maxi = profit[i];
        index = i;
      }
      
    }

    if (maxi==0)
    {
      break;
    }
    

    ans+=maxi;
    profit[index]-=1;
    
  }
  
  cout<<ans<<endl;

  /*
  Optimization
  Max Heap 
  On Each Iteration take Maximum Element
  Add it into ans and store it it again in the heap with decrementing the value by one
  Time (nlogn + klogn) 
  Space = O(n)
  */

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

