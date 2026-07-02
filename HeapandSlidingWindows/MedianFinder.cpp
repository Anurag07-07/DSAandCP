#include<bits/stdc++.h>
using namespace std;
/*
Brute Force

Create an array and store the element inside it in sorted order
When Double is called chcek if even length return mid+mid+1/2 and if odd retunrn mid/2

*/

class MedianFinder {
  public:
    vector<int> ans;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      ans.push_back(num);
      sort(ans.begin(),ans.end());
    }
    
    double findMedian() {
      //Find the Length
      int n = ans.size();
      int start = 0;
      int end = n-1;
      double value;
      int mid = start+(end-start)/2;
      if (n%2==0)
      {
        int mid1 = ans[mid];
        int mid2 = ans[mid+1];
        value = (mid1+mid2)/2.0;
      }else{
        value = ans[mid]/1.0;
      }
      return value;  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /*
 Optimal

 To Array ko sort karke median nikala 
 Lekin what i observe is is pure sorted se lena dena hi nahi hai 
 Sirf middle element jo hai uska right side ka sabse chota element middle se bda ya brabar ho
 and left side ka sabse bda element middle se chota ya brabar ho 
 To main kya chahta hu ki main jab kisi element ko middle manu to uske left ka max ek baar me bta chal jaye and right ka min bhi
 to yaha se main max and min heap soch sakta hu

 Thik hai to max and min heap bna lete hai hai element kaise insert honge 
 Mughe ye bta hai ki right side ke element equal hone chahiye count me right side ke 
 to maxheap me max to max 1 element extra hota hai 

 Agar odd length ki array hai to max heap ka top return kar do 
 Agar even length ki array hai to min heap ka top and max heap ka top / 2.0 return kar do 
 */

class MedianFinder {
  public:
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>> p2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (p1.empty() || p1.top()>=num)
        {
          p1.push(num);
        }else{
          p2.push(num);
        }
        
        if (p1.size()>p2.size()+1)
        {
          p2.push(p1.top());
          p1.pop();
        }else if (p1.size()<p2.size())
        {
          p1.push(p2.top());
          p2.pop();
        }
    }
    
    double findMedian() {
      if (p1.size()==p2.size())
      {
        return (p1.top()+p2.top())/2.0;
      }
      return p1.top();         
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */