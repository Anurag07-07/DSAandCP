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
    // ListNode* removeElements(ListNode* head, int val) {
    //   ListNode* curr = head;        
    //   ListNode* prev = nullptr;
    //   if (!head)
    //   {
    //     return nullptr;
    //   }

    //   while (head!=nullptr && head->val == val)
    //   {
    //     head = head->next;
    //   }
    //   if (!head)
    //   {
    //     return head;
    //   }
      
    //   while (curr)
    //   {
    //     if (curr->val==val)
    //     {
    //       prev->next = curr->next;
    //       curr = prev->next;
    //     }else{
    //       prev = curr;
    //       curr = curr->next;
    //     }
    //   }
    //  return head;             
    // }

    ListNode* RemoveNode(ListNode* head,int val){
      //Last tak chala gya aur ab list return hogi jo ki baki lisst se combine hogi
      // Wo Null Hogi
      if (head==nullptr)
      {
        return head;
      }
      //agar head par element hai wo remvoe karna hai to wo aage ki list me nahi jayega esliye pehle se aayi list hi return kar dunga
      if (head->val==val)
      {
        return RemoveNode(head->next,val);
      }
      //Nahi to current head ko jorunga aayi hui list ke saath and aage begh dunga
      head->next = RemoveNode(head->next,val);
      return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
      return RemoveNode(head,val);
    }
};