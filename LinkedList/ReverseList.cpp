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


ListNode* reverse(ListNode* head){
      //Jab bbhi nye head na next null ho jaye wahi se return ho jana
      if (head==nullptr || head->next==nullptr)
      {
        return head;
      }
      
      //Agar Last tak pahuch to nya head koi aaya hoga wo head ko store karunga and usi ko return kar dunga
      ListNode* newhead = reverse(head->next);  //Current head ke aage ka sab reverse kar do aur jo nya head mile usse return kar dena 
      //Now Link karo 
      //Current head kon hai suppose 2  2
      //New Head me kya aaya suppose 3  3->null
      //To 3 ke baad current head 2 add  hoga  aur null 2 ke baad 3->2->null
      //Original List me hi change karna hai to ussi ka access lena padega
      // to current head 2 ka next 3 and uske next me mughe current head dalna hai 
      head->next->next = head;
      head->next = nullptr;
      //New head 3 Return kar do
      return newhead; 
    }
    ListNode* reverseList(ListNode* head) {
      return reverse(head);
    }

ListNode* AddTwoNumber(ListNode* headA,ListNode* headB){
  //Reverse The Lists
  ListNode* r1 = reverse(headA);
  ListNode* r2 = reverse(headB);

  ListNode* dummy = new ListNode(0);
  ListNode* tail = dummy;
  int carry = 0;
  while (r1!=nullptr && r2!=nullptr)
  {
    //Take both Element
    int value1 = r1->value;
    int value2 = r2->value;
    //Find Element to store and carry
    int numb = (value1+value2+carry)%10;
    carry = (value1+value2+carry)/10;
    tail->next = new ListNode(numb);
    tail = tail->next;
    r1 = r1->next;
    r2 = r2->next;
  }

  while (r1!=nullptr)
  {
    //Take both Element
    int value1 = r1->value;
    //Find Element to store and carry
    int numb = (value1+carry)%10;
    carry = (value1+carry)/10;
    tail->next = new ListNode(numb);
    tail = tail->next;
    r1 = r1->next; 
  }

  while (r2!=nullptr)
  {
    //Take both Element
    int value2 = r2->value;
    //Find Element to store and carry
    int numb = (value2+carry)%10;
    carry = (value2+carry)/10;
    tail->next = new ListNode(numb);
    tail = tail->next;
    r2 = r2->next;
  }

  if (carry)
  {
    tail->next = new ListNode(carry%10);
    carry/=10; 
  }
  ListNode* ans = reverse(dummy->next);
  return ans;  
}

ListNode* reverseinGroupofK(ListNode* head,int K){
  if (head==nullptr || head->next==nullptr)
  {
    return head;
  }
  //Reverse kar do k element ko baki aage begh to wo rverse hoke aayega usko connect kar dena

  ListNode* curr = head;
  ListNode* next = nullptr;
  ListNode* prev = nullptr;
  int count = 0;
  while (curr!=nullptr && count<K)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
  
  head->next = reverseinGroupofK(curr,K);
  return prev;
}

int main(int argc, char const *argv[])
{
  ListNode* h1 = CreateList(5);
  ListNode* h2 = CreateList(4);
  ListNode* ans = AddTwoNumber(h1,h2);
  Traversal(ans);
  return 0;
}