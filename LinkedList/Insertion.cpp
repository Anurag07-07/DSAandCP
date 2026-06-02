#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int value){
    data = value;
    next = nullptr;
  }
};

Node* CreateList(int n){
  Node* head = nullptr;
  Node* tail = nullptr;
  for (int i = 0; i < n; i++)
  {
    int x;cin>>x;
    Node* temp = new Node(x);

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

void Traversal(Node* head){
  Node* temp = head;
  while (temp!=nullptr)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"->end"<<endl;
}

void RecursiveTraversal(Node* head){
  if(head==nullptr){
    return;
  }
  cout<<head->data<<"->";
  RecursiveTraversal(head->next);
}

bool Search(Node* head,int target){
  Node* temp = head;

  while (temp!=nullptr)
  {
    if (temp->data==target)
    {
      return true;
    }
    
    temp = temp->next;
  }
  return false;
}

bool RecursiveSearch(Node* head,int target){
  if (head==nullptr)
  {
    return false;
  }

  if (head->data==target)
  {
    return true;
  }
  
  return RecursiveSearch(head->next,target);
}

int lengthofLinkedList(Node* head){
  Node* temp = head;
  int count = 0;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int lengthofLinkedListRecursive(Node* head){
  if(head==nullptr){
    return 0;
  }
  return 1+lengthofLinkedListRecursive(head->next);
}

Node* InsertatBeginning(Node* head,int val){
  //If No Head
  if (head==nullptr)
  {
    head = new Node(val);
  }else{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
  }
  
  return head;
}

int main()
{
  int n;cin>>n;
  Node* l1 = CreateList(n);
  // RecursiveTraversal(l1);
  // cout<<lengthofLinkedListRecursive(l1);
  Node* l2 = InsertatBeginning(l1,5);
  RecursiveTraversal(l2);
  return 0;
}
