/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class ListNode{
  public:
  int val;
  ListNode* next;
  ListNode(int data){
    this->val = data;
  }
};

class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //   ListNode* prev = nullptr;
    //   ListNode* curr = head;
    //   ListNode* next = nullptr;
    //   while (curr)
    //   {
    //     next = curr->next;
    //     curr->next = prev;
    //     curr = next;
    //     prev = curr;
    //   }
    //   return prev;     
    // }
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
};
