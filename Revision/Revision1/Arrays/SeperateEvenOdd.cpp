#include<bits/stdc++.h>
using namespace std;
vector<int> Brute(vector<int> nums){
  //Rather Than Creating a three array create one array and store
  //all the even odd by iterating over the array two time
  vector<int> temp;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i]%2==0)
    temp.push_back(nums[i]);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i]%2==1)
    temp.push_back(nums[i]);
  }

  nums = temp;
  return nums;
}

vector<int> Optimal(vector<int> nums){
  //There are two pointer i and j  
  // i carry even and j carry odd
  // So there are three condition 
  // if i is even i++
  // if j is odd j--
  // if i is odd and j is even swap i and j element
  int size = nums.size();
  int i = 0;
  int j = size-1;
  while (i<j)
  {
    if(nums[i]%2==0) i++;
    else if(nums[j]%2==1) j--;
    else{
      swap(nums[i],nums[j]);
      i++;
      j--;
    }
  }
  return nums;
}

int main()
{
  vector<int> nums{1,5,6,4,2,3,8};
  vector<int> ans = Optimal(nums);
  for(int x:ans){
    cout<<x<<" ";
  }
  return 0;
}
