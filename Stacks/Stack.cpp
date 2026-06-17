#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    next = nullptr;
  }
};



class MinStack {
public:
stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
      if (st.empty())
      {
        st.push(make_pair(value,value));
      }else{
        int mini = min(value,st.top().second);
        st.push(make_pair(value,mini));
      }
      
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
      if (st.empty())
      return-1;
      
      return st.top().first;
    }
    
    int getMin() {
      if (st.empty())
      return-1;

      return st.top().second;
    }
};


class StackArray{
  int *arr;
  int size;
  int top;
  public:
  bool flag;
  StackArray(int s){
    size = s;
    top = -1;
    arr = new int[s];
    flag = 1;
  }
  void push(int val){
    if (top==size)
    {
      cout<<"Stack Overflow"<<endl;      
    }else{
      top++;
      arr[top] = val;
      flag = 0;
    }
  }
  void pop(){
    if (top==-1 )
    {
      cout<<"Stack Underflow"<<endl;
    }else{
      top--;
      if (top==-1)
      {
        flag = 1;
      }
    }
  }

  int peek(){
    if (top==-1)
    {
      cout<<"Stack is Empty"<<"\n";
      return -1;
    }
    
    return arr[top];
  }

  int issize(){
    return top+1;
  }

  bool isEmpty(){
    if (top==-1)
    {
      return true;
    }
    return false;
  }
};

class StackLL{
  ListNode *top;
  int size;
  public:
  StackLL(){
    top = nullptr;
    size = 0;
  }

  void push(int val){
    ListNode* temp = new ListNode(val);
    if (temp==nullptr)
    {
      cout<<"Stack Overflow"<<endl;
      return;
    }else{
      temp = temp->next;
      top = temp;
      size++;
    }
    
  }

  void pop(){
    if (top==nullptr)
    {
      cout<<"Stack Underflow\n";
      return;
    }else{
      ListNode* temp = top;
      top = top->next;
      delete temp;
    }
    
  }

  int peek(){
    if (top == nullptr)
    {
      cout<<"Stack is Empty\n";
    }else{
      return top->val;
    }
    
  }

  bool isEmpty(){
    return top=nullptr;
  }

  int isSize(){
    return size;
  }
};


ListNode* CreateLL(int n){
  ListNode* head = new ListNode(0);
  ListNode* tail = head;

  int val;
  while (n--)
  {
    cin>>val;
    tail->next = new ListNode(val);
    tail = tail->next;
  }
  return head->next;
}

void Traversal(ListNode* head){
  if (head==nullptr)
  {
    return;
  }
  cout<<head->val<<" ";
  Traversal(head->next);
}

int main()
{
  // vector<int> nums{1,2,3,4,5,6};
  
  // stack<int> s;
  // for (int i = 0; i < nums.size(); i++)
  // {
  //   s.push(nums[i]);
  // }

  // while (!s.empty())
  // {
  //   cout<<s.top()<<" ";
  //   s.pop();
  // }

  ListNode* l1 = CreateLL(5);
  stack<int> s;
  ListNode* curr = l1;
  while (curr!=nullptr)
  {
    s.push(curr->val);
    curr = curr->next;
  }
  
  
  while (!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  
  
  return 0;
}
