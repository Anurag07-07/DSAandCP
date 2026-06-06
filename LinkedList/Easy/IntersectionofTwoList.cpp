/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tail1 = headA;
      ListNode* tail2 = headB;

      while (tail1->next!=nullptr)
      {
        tail1  = tail1->next;
      }

      while (tail2->next!=nullptr)
      {
        tail2  = tail2->next;
      }

      if (tail1!=tail2)
      {
        return nullptr;
      }
        

      tail1->next = headA;
      
      //Run the Slow Fast Pointer till they not meet each other
      ListNode* slow = headB;
      ListNode* fast = headB;
      while (fast!=nullptr && fast->next!=nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
          break;
        }
      }

      if(fast==nullptr || fast->next==nullptr){
        tail1->next = nullptr; 
        return nullptr; 
      }
      
      slow = headB;
      while (slow!=fast)
      {
        slow = slow->next;
        fast = fast->next;
      }

      tail1->next = nullptr;

      return slow;
    }
};