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
    // ListNode* deleteDuplicates(ListNode* head) {
    //   if  (!head || !head->next)
    //   {
    //     return head;
    //   }
      
      
    //   ListNode* curr = head->next;
    //   ListNode* prev = head;
    //   while (curr)
    //   {
    //     if (curr->val==prev->val)
    //     {
    //       prev->next = curr->next;
    //       delete curr;
    //       curr = prev->next;
    //     }else{
    //       prev = curr;
    //       curr = curr->next;
    //     }
    //   }
    //   return head;
    // }
    ListNode* Remove(ListNode* head){
      if (head==nullptr || head->next==nullptr)
      {
        return head;
      }

      if (head->val==head->next->val)
      {
        return Remove(head->next);
      }else{
        head->next = Remove(head->next);
        return head;
      }
    }
    ListNode* deleteDuplicates(ListNode* head) {
      if (!head)
      {
        return head;
      }
      
      return Remove(head);
    }
};