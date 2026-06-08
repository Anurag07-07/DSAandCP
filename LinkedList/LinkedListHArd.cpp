#include<bits/stdc++.h>
using namespace std;
class ListNode{
  public:
  int val;
  ListNode* next;
  ListNode* bottom;
  ListNode(int val){
    this->val = val;
    next = nullptr;
    bottom = nullptr;
  }
};

ListNode* mergeFlatten(ListNode* head1, ListNode*head2){
  ListNode* head = new ListNode(0);
  ListNode* tail = head;
  while (head1&& head2)
  {
    if (head1->val<=head2->val)
    {
      tail->bottom = head1;
      head1 = head1->bottom;
      tail = tail->bottom;
      tail->bottom = nullptr;
    }else{
      tail->bottom = head2;
      head2 = head2->bottom;
      tail = tail->bottom;
      tail->bottom = nullptr;
    }
    
  }

  if(head1){
    tail->bottom = head1;
  }else{
    tail->bottom = head2;
  }
  return head->bottom;
}

ListNode* mergeK(ListNode* head1, ListNode*head2){
  ListNode* head = new ListNode(0);
  ListNode* tail = head;
  while (head1&& head2)
  {
    if (head1->val<=head2->val)
    {
      tail->next = head1;
      head1 = head1->next;
      tail = tail->next;
      tail->next = nullptr;
    }else{
      tail->next = head2;
      head2 = head2->next;
      tail = tail->next;
      tail->next = nullptr;
    }
    
  }

  if(head1){
    tail->next = head1;
  }else{
    tail->next = head2;
  }
  return head->next;
}

ListNode* flatten(ListNode* root){
  ListNode* head1 = nullptr;
  ListNode *head2 =nullptr;
  ListNode *head3 = nullptr;
  while (root->next)
  {
    head1 = root;
    head2 = root->next;
    head3 = root->next->next;
    head1->next = nullptr;
    head2->next = nullptr;
    root = mergeFlatten(head1,head2);
    root->next = head3;
  }

  return root->bottom;
}

ListNode* mergeKListsBrute(ListNode* arr[],int k){
  ListNode* head = arr[0];
  for (int i = 1; i < k; i++)
  {
    head = mergeK(head,arr[i]);
  }
  return head;
} 

void mergeSort(ListNode* arr[],int start,int end){
  if (start>=end)
  {
    return;
  }
  int mid =  start+(end-start)/2;
  mergeSort(arr,start,mid);
  mergeSort(arr,mid+1,end);
  arr[start] = mergeK(arr[start],arr[mid+1]);
}

ListNode* find(ListNode* curr1,ListNode* curr2,ListNode* x){
  if (x==nullptr)
  {
    return nullptr;
  }
  
  while (curr1!=x)
  {
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return curr2;
}

ListNode* Clone(ListNode* head){
  ListNode* headCopy = new ListNode(0);
  ListNode* tailCopy = headCopy;
  ListNode* temp = head;
  while (temp)
  {
    tailCopy->next = new ListNode(temp->val);
    tailCopy = tailCopy->next;
    temp = temp->next;
  }

  tailCopy = headCopy;
  headCopy = headCopy->next;
  delete tailCopy;

  tailCopy = headCopy;
  temp = head;
  while (temp)
  {
    tailCopy->bottom = find(head,headCopy,temp->bottom);
    tailCopy = tailCopy->next;
    temp = temp->next;
  }
  return headCopy;
}

