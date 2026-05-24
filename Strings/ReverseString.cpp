//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

i       j
// h e l l o
//   i   j
// o e l l h
//     ij
// o l l e h
//   j   i
// o l l e h
//
// o l l e h

int main(int argc, char *argv[]) {
   vector<string> nums{"h","e","l","l","o"};
   //If i use Stl
   // reverse(nums.begin(),nums.end());

   int n = nums.size();
   int i = 0;
   int j = n-1;
   while (i<=j) {
      swap(nums[i],nums[j]);
      i++;
      j--;
   }
   return 0;
}
