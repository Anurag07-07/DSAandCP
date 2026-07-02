#include<bits/stdc++.h>
using namespace std;
// Smallest Range covering all elements form K list
/*
Brute

Dump all element in one array and  find the possible range by taken two element at a time
How to find that possible pair
By taking a pair and serach the element in all the array within the range
Time Complexity = O((nk)^3

Better
Min Heap
Pehla element le lo sare arrays ka and ek range create kar lo min to max
min to min heap ke through mil jayega baar baar nya element dalunga
and max naya dalte waqt hi upate kar dunga
range ko kam karna hai to min ko bhadhao rather than max ko gatao kyoki yaha max nahi ghatega aage aur bade element hai
to esliye min ko update karenge 
*/

vector<int> Solution(){
  vector<int> arr1{10,15,18,20};
  vector<int> arr2{0,6,8,4};
  vector<int> arr3{3,9,11,14};
  vector<vector<int>> nums;
  nums.push_back(arr1);
  nums.push_back(arr2);
  nums.push_back(arr3);
  priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
   > p;
  int minimum,maximum = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    p.push(make_pair(nums[i][0],make_pair(i,0)));
    maximum = max(maximum,nums[i][0]);
  }
  
  minimum = p.top().first;
  vector<int>ans(2);
  ans[0] = minimum;
  ans[1] = maximum;

  pair<int,pair<int,int>> temp;
  int row,col,elem;
  while (p.size()==nums.size())
  {
    temp = p.top();
    p.pop();

    elem = temp.first;
    row = temp.second.first;
    col  = temp.second.second;

    if (col+1<nums[row].size())
    {
      col++;
      p.push(make_pair(nums[row][col],make_pair(row,col)));
      maximum = max(maximum,nums[row][col]);
      minimum = p.top().first;

      if (maximum-minimum<ans[1]-ans[0])
      {
        ans[0] = minimum;
        ans[1] = maximum;
      }
      
    }

  }
  return ans;
}


// Contruct Target Array with Mutiple Sum 


int main(int argc, char const *argv[])
{
  return 0;
}
