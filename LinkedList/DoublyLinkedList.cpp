#include<bits/stdc++.h>
using namespace std;
class DLL{
  public:
  int val;
  DLL* next;
  DLL* prev;
  DLL(int data){
    val = data;
    next = nullptr;
    prev = nullptr;
  }
};

DLL* InsertatBeginning(DLL* head,int value){
  if (head==nullptr)
  {
    head = new DLL(value);
  }else{
    DLL* temp = new DLL(value);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  return head;
}

DLL* InsertatEnd(DLL* head,int value){
  if (head==nullptr)
  {
    head = new DLL(value);
  }else{
    DLL* curr = head;
    while (curr->next)
    {
      curr = curr->next;
    }
    //Create Node
    DLL* temp = new DLL(value);
    temp->prev = curr;
    curr->next = temp;
  }
  return head;
}

DLL* DLLUsingArray(vector<int>& nums){
  DLL* head = nullptr;
  DLL* tail = head;
  for (int i = 0; i < nums.size(); i++)
  {
    if (head==nullptr)
    {
      head = new DLL(nums[i]);
      tail = head;
    }else{
      DLL* temp = new DLL(nums[i]);
      temp->prev = tail;
      tail->next = temp;
      tail = temp;
    }
  }
  return head;
}

DLL* CreateDLL(vector<int>& nums,int start,int end,DLL* back){
  if (start==end)
  {
    return nullptr;
  }
  //Create Node
  DLL* temp = new DLL(nums[start]);
  temp->prev = back;
  temp->next = CreateDLL(nums,start+1,end,temp);
  return temp;
}

void Traversal(DLL* head){
  DLL* curr = head;
  while (curr)
  {
    cout<<curr->val<<"->";
    curr = curr->next;
  }
  cout<<endl;
}

DLL* InsertatPosition(DLL* head,int pos,int val){
  if (pos==0)
  {
    if (head==nullptr)
    {
      head = new DLL(val);
    }else{
      return InsertatBeginning(head,val);
    }
  }

  int count = 0;
  DLL* temp = head;
  while (temp->next)
  {
    count++;
    temp = temp->next;
  }

  if (pos==count)
  {
    return InsertatEnd(head,val);
  }else{
    DLL* curr = head;
    while (--pos)
    {
      curr = curr->next;
    }
    //Create new Node
    DLL* temp = new DLL(val);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next = temp;
    temp->next->prev = temp; 
  }
  return head;
}

DLL* DeleteatStart(DLL* head){
  if (head==nullptr || head->next == nullptr)
  {
    return nullptr;
  }else{
    DLL* temp = head;
    head = head->next;
    temp->next = nullptr;
    head->prev = nullptr;
    delete temp;
  }
  return head;
}

DLL* DeleteatEnd(DLL* head){
  if (head==nullptr || head->next == nullptr)
  {
    return nullptr;
  }else{
    DLL* temp = head;
    
    while (temp->next)
    {
      temp = temp->next;
    }

    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }
  return head;
}

DLL* DeleteatPosition(DLL* head,int pos){
  if (pos==0)
  {
    if (head==nullptr || head->next == nullptr)
    {
      return nullptr;
    }else{
      return DeleteatStart(head);
    }
    
  }else{
    DLL* temp = head;
    while (pos--)
    {
      temp = temp->next;
    }
    if (temp->next==nullptr)
    {
      return DeleteatEnd(head);
    }else{
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp;
    }
    
  }
  return head;
}

int main()
{
  vector<int> nums{1,2,3,4,5,6};
  // DLL* l1 = DLLUsingArray(nums);
  DLL* l1 = CreateDLL(nums,0,nums.size(),nullptr);
  // DLL* l2 = InsertatPosition(l1,3,100); // after 3 element 
  // DLL* l3 = DeleteatStart(l1);
  // DLL* l4 = DeleteatEnd(l1);
  DLL* l5 = DeleteatPosition(l1,3);
  Traversal(l5);
  return 0;
}
