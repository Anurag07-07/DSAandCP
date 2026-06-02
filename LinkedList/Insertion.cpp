#include<bits/stdc++.h>
using namespace std;
class ListNode{
  public:
  int value;
  ListNode* next;
  ListNode(int value){
    this->value = value;
    next = nullptr;
  }
};

ListNode* CreateList(int n){
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (int i = 0; i < n; i++)
  {
    int x;cin>>x;
    ListNode* temp = new ListNode(x);

    if (head==nullptr)
    {
      head = temp;
      tail = temp;
    }else{
      tail->next = temp;
      tail = temp;
    }
    
  }
  return head;
}

void Traversal(ListNode* head){
  ListNode* temp = head;
  while (temp!=nullptr)
  {
    cout<<temp->value<<"->";
    temp = temp->next;
  }
  
  cout<<"->end"<<endl;
}

void RecursiveTraversal(ListNode* head){
  if(head==nullptr){
    return;
  }
  cout<<head->value<<"->";
  RecursiveTraversal(head->next);
}

bool Search(ListNode* head,int target){
  ListNode* temp = head;

  while (temp!=nullptr)
  {
    if (temp->value==target)
    {
      return true;
    }
    
    temp = temp->next;
  }
  return false;
}

bool RecursiveSearch(ListNode* head,int target){
  if (head==nullptr)
  {
    return false;
  }

  if (head->value==target)
  {
    return true;
  }
  
  return RecursiveSearch(head->next,target);
}

int lengthofLinkedList(ListNode* head){
  ListNode* temp = head;
  int count = 0;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int lengthofLinkedListRecursive(ListNode* head){
  if(head==nullptr){
    return 0;
  }
  return 1+lengthofLinkedListRecursive(head->next);
}

ListNode* RemoventhNode(ListNode* head,int n){
  int count = 0;
  ListNode* temp = head;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  count-=n;
  if (count==0)
  {
    temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  temp = head;
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (count--)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  delete curr;
  return head;
}

ListNode* RemovekthNode(ListNode* head,int K){
  int count = 1;

  if (K==1)
  {
    return nullptr;
  }
  

  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (curr!=nullptr)
  {
    if (count==K)
    {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
      count=1;
    }else{
      prev = curr;
      curr = curr->next;
      count++;
    }
  }
  return head;
}



ListNode* RotateList(ListNode* head,int K){
  if (head==nullptr || head->next == nullptr)
  { 
    return head;
  }
  
  int totalNode = 0;
  ListNode* temp = head;
  while (temp!=nullptr)
  {
    totalNode++;
    temp = temp->next;
  }

  K%=totalNode;
  if(K==0) return head;
  
  totalNode-=K;

  //Skip z = total-K Node from Start
  ListNode* prev = nullptr;
  ListNode* curr = head;
  while (totalNode--)
  {
    prev = curr;
    curr = curr->next;
  }

  prev->next = nullptr;
  ListNode* tail = curr;
  
  while (tail->next)
  {
    tail = tail->next;
  }

  tail->next = head;
  return curr;
}

bool Palindrone(ListNode* head,int K){
  if (head->next==nullptr)
  {
    return 1;
  }
  
  ListNode* temp = head;
  //Count Node
  int count = 0;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  count/=2;

  //Split
  ListNode* curr = head;
  ListNode* prev = nullptr;
  while (count--)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = nullptr;

  //Rotate
  ListNode* futr = nullptr;
  ListNode* prev = nullptr;
  while (curr)
  {
    futr = curr->next;
    curr->next = prev;
    prev = curr;
    curr = futr;
  }
  //Previous Hold Last Node
  //Check if plaindrone or not
  ListNode* head1 = head;
  ListNode* head2 = prev;
  while (head1!=nullptr)
  {
    if (head1->value!=head2->value)
    {
      return 0;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  return 1;
}

ListNode* InsertatBeginning(ListNode* head,int val){
  //If No Head
  if (head==nullptr)
  {
    head = new ListNode(val);
  }else{
    ListNode* temp = new ListNode(val);
    temp->next = head;
    head = temp;
  }
  
  return head;
}

int main()
{
  int n;cin>>n;
  ListNode* l1 = CreateList(n);
  // RecursiveTraversal(l1);
  // cout<<lengthofLinkedListRecursive(l1);
  ListNode* l2 = InsertatBeginning(l1,5);
  RecursiveTraversal(l2);
  return 0;
}
