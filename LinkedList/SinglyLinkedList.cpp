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
  prev = nullptr;
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

ListNode* InsertatBeginning(ListNode* head,int data){
if (head==nullptr)
{
  head = new ListNode(data);
}else{
  ListNode* temp = new ListNode(data);
  temp->next = head;
  head = temp;
}
return head;
}

ListNode* InsertatEnd(ListNode* head,int data){
if (head==nullptr)
{
  head = new ListNode(data);
}else{
  ListNode* curr = head;
  while (curr->next)
  {
    curr = curr->next;
  }
  ListNode* temp = new ListNode(data);
  curr->next = temp;
}
return head;
}

ListNode* InsertatPosition(ListNode* head,int data,int pos){
if (pos==0)
{
  if (head==nullptr)
  {
    head = new ListNode(data);
    return head;
  }else{
    return InsertatBeginning(head,data);
  }
}else{
  ListNode* curr = head;
  while (--pos)
  {
    curr = curr->next;
  }
  if (curr->next==nullptr)
  {
    return InsertatEnd(head,data);
  }else{
    ListNode* temp = new ListNode(data);
    temp->next = curr->next;
    curr->next = temp;
  }
  return head;
}
return head;
}

ListNode* DeletefromStart(ListNode* head){
  if (head ==nullptr || head->next == nullptr)
  {
    return nullptr;
  }else{
    ListNode* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
  }
  return head;
}

ListNode* DeletefromEnd(ListNode* head){
  if (head ==nullptr || head->next == nullptr)
  {
    return nullptr;
  }else{
    ListNode* temp = head;
    while (temp->next->next)
    {
      temp->next;
    }
    temp->next = nullptr;
  }
  return head;
}

ListNode* DeletefromPos(ListNode* head,int pos){
  if (pos==0)
  {
    if (head ==nullptr || head->next == nullptr)
    {
      return nullptr;
    }else{
      return DeletefromStart(head);
    }
  }
  int count = 0;
  ListNode* curr = head;
  while (curr!=nullptr)
  {
    count++;
    curr = curr->next;
  }
  if (pos==count-1)
  {
    return DeletefromEnd(head);
  }else{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (pos--)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    delete curr; 
  }
  return head;
}

ListNode* RemoveDuplicates(ListNode* head){
  if (!head || !head->next)
  {
    return head;
  }
  
  ListNode* prev = head;
  ListNode* curr = head->next;
  while (curr)
  {
    if (curr->value==prev->value)
    {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    }else{
      prev = prev->next;
      curr = curr->next;
    }
  }
  return head;
}

ListNode* MergeTwoSortedList(ListNode* head1,ListNode* head2){
  ListNode* curr = new ListNode(0);
  ListNode* tail = curr;
  ListNode* curr1 = head1;
  ListNode* curr2 = head2;
  while (curr1 && curr2)
  {
    if (curr1->value<curr2->value)
    {
      tail->next = curr1;
      curr1 = curr1->next;
      tail = tail->next;
      tail->next = nullptr;
    }else{
      tail->next = curr2;
      curr2 = curr2->next;
      tail = tail->next;
      tail->next = nullptr;
    }
  }

  if (curr1)
  {
    tail->next = curr1;
  }else{
    tail->next = curr2;
  }
  
  return curr->next;
}

ListNode* SortList(ListNode* head){
  int count_zero = 0;
  int count_one = 0;
  int count_two = 0;
  ListNode* curr = head;
  while (curr)
  {
    if (curr->value==0)
    {
      count_zero++;
    }else if (curr->value==1)
    {
      count_one++;
    }else{
      count_two++;
    }
  }

  curr = head;
  while (count_zero--)
  {
    curr->value = 0;
    curr = curr->next;
  }
  while (count_one--)
  {
    curr->value = 1;
    curr = curr->next;
  }
  while (count_two--)
  {
    curr->value = 2;
    curr = curr->next;
  }
  return head;
}

int main()
{
  int n;cin>>n;
  ListNode* l1 = CreateList(n);
  ListNode* l2 = CreateList(n);
  // RecursiveTraversal(l1);
  // cout<<lengthofLinkedListRecursive(l1);
  ListNode* l3 = MergeTwoSortedList(l1,l2);
  RecursiveTraversal(l3);
  return 0;
}
