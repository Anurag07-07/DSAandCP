#include<bits/stdc++.h>
using namespace std;

// 1   5   9

// 10 11 13

// 12 13 15


/*
Brute 
Copy karo into 1D array 
Sort the Array N2Logn^2
Return Kth Smallest Element
Time N^2logn


Better 
Iterate Over an Array and Store all element Inside 1D Array
Create The Min Heap 
And K Element
Time N^2+Klogn

Optimal
Two Pointer me agar hame do array sort karne ko bole to kaise karte the 
do array par do pointer rakho and min value ko array me daal do and pointer ko aage bdha do 
to socho hum kar kya rahe hai min nikal rahhe aur array me daal rahe waise hi 
agar das array me ek saath bol de to kya karnege ? 
un sabka sabse pehla elment lenge aur min ko array me daal denge aur wo pointer aage kar denge 
to esa kon hai jo das element me se min ek baar me de de ? min heap to hum wo use karenge 
lekin ye kaise pata chalega ki agla element kon sa dalu to woto next element hi hoga 
to hum current element ka index of row and col bhi rakh lenge ki next element ka row same and col+1 hoga wo insert kar sake
Agar humne kth smallest nikalna hai to k-1 element nikal do heap se aur ab jo element top par hoga wahi kth smallest hoga


Most Optimal
Binary Search 
range => hame kya pta hai ki agar kth smallest  hai to 0,0 elment se n-1,n-1 element ke bich me hi hoga
to main yahi start and end range maan lunga
ab mid nikalunga ye mid mera kth smallesst hoga and agar ye kth smallest hai to eske pehle ya yaha tak k element honge agara hai to ye mera possible answer hai
and ab main left side jaunga and nahi hai to right side jaunga 

count nikal ne ke liye row = n-1 and col = 0 par khada rahunga and dekh lunga ki wo element
kya mere mid se bda hai agar bda hai to pehle to aa nahi sakta mid ke to main row me upar jaunga 
and agar chota hai to main pta kar lunga ki es same row me aur kitne chote hai 
wo sare eske upar wale hi honge
wo kaise niklega ? 
jis row par khata hu wo yahi bta raha ki eske upar kitne chote hai and esko zorenge to row+1 ho jayega
and then col me aage jayenge
*/

int KthSmallest(vector<vector<int>>& nums,int k){
  int n = nums.size();
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
  for (int i = 0; i < n; i++)
  {
    p.push(make_pair(nums[0][i],make_pair(i,0)));
  }
  
  while (--k)
  {
    pair<int,pair<int,int>> temp = p.top();
    p.pop();
    int value = temp.first;
    int row = temp.second.first;
    int col = temp.second.second;

    if (col+1<n)
    {
      p.push(make_pair(nums[row][col+1],make_pair(row,col+1)));
    }
  }
  return p.top().first;
}

int countNumberLess(vector<vector<int>> nums,int count){
  int n = nums.size();
  int i = n-1;
  int j = 0;
  while (i>=0 && j<n)
  {
    if (nums[i][j]<=count)
    {
      count+=i+1;
      j++;
    }else{
      i--;
    }
  }
  
  return count;
}

int KthSmallestOptimal(vector<vector<int>>& nums,int k){
  int n = nums.size();
  int start = nums[0][0];
  int end = nums[n-1][n-1];
  int ans = -1;
  while (start<=end)
  {
    int mid = start+(end-start)/2;

    int count = countNumberLess(nums,mid);

    if (count<k)
    {
      start = mid+1;
    }else{
      ans = mid;
      end = mid-1;
    }
    
  }
}

// int kthSmallest(int mat[INT_MAX][INT_MAX],int n,int k){
//   //Create Min Heap
//   vector<pair<int,pair<int,int>>> temp;
//   for (int i = 0; i < n; i++)
//   {
//     temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
//   }
  
//   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p(temp.begin(),temp.end());

//   int ans;
//   pair<int,pair<int,int>> element;
//   int i,j;
//   while (k--)
//   {
//     element = p.top();
//     p.pop();
//     ans = element.first;//value
//     i = element.second.first; //row number
//     j = element.second.second; //col number

//     if (j+1<n)
//     {
//       p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
//     }
    
//   }
//   return ans;
// }
int main(int argc, char const *argv[])
{
  return 0;
}