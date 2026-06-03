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

// bool Check(vector<ListNode*> checked, ListNode* curr){
//     for (int i = 0; i < checked.size(); i++)
//     {
//       if (checked[i]==curr)
//       {
//         return 1;
//       }
      
//     }
//   return 0;    
// }


// bool DetectLoop(ListNode* head){
//   ListNode* curr = head;
//   vector<ListNode*> visited;
//   while (curr)
//   {
//     if (Check(visited,curr))
//     {
//       return true;
//     }
//     visited.push_back(curr);
//     curr = curr->next;
//   }
//   return false;
// }

bool Check(unordered_map<ListNode*,int> mp,ListNode* curr){
  if (mp.count(curr)==1)
  {
    return true;
  }
  return false;
}


bool DetectLoop(ListNode* head){
  ListNode* curr = head;
  // unordered_set<ListNode*> s;
  unordered_map<ListNode*,int> mp;
  while (curr)
  {
    if (Check(mp,curr))
    {
      return true;
    }

    // s.insert(curr);
    mp.insert({curr,1});
    curr = curr->next;
  }
  return false;
}

bool LoopDetect(ListNode* head){
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow==fast)
    {
      return true;
    }

  }
  return false;
}

int LoopLength(ListNode* head){
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow==fast)
    {
    break;
    }
  }

  if (fast!=nullptr && fast->next!=nullptr)
  {
    return 0;
  }
  slow = slow->next;
  int count = 1;
  while (slow!=fast)
  {
    count++;
    slow = slow->next;
  }
  return count;
}

ListNode* LoopBreak(ListNode* head){
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast!=nullptr && fast->next!=nullptr)
  {
    
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow==fast)
    {
    break;
    }
  }

  if (fast!=nullptr && fast->next!=nullptr)
  {
    return 0;
  }
  slow = head;
  while (slow!=fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  
  while (slow->next!=fast)
  {
    slow = slow->next;
  }
  slow->next = nullptr;
  return head;
}

int IntersectionofNode(ListNode* head1,ListNode* head2){
  //Count Number of Nodes
  ListNode* curr1 = head1;
  ListNode* curr2 = head2;
  int count1= 0;
  int count2= 0;
  while (curr1)
  {
    count1++;
    curr1 = curr1->next;
  }

  while (curr2)
  {
    count1++;
    curr2 = curr2->next;
  }

  while (count1>count2)
  {
    curr1 = curr1->next;
    count1--;
  }

  while (count1<count2)
  {
    curr2 = curr2->next;
    count2--;
  }
  
  while (curr1!=curr2)
  {
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  
  if (!curr1)
  {
    return -1;
  }
  
  return curr1->value;
}


int main()
{
  int n;cin>>n;
  ListNode* l1 = CreateList(n);
  cout<<DetectLoop(l1);
  return 0;
}
