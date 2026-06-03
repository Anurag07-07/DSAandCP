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
    ListNode* middleNode(ListNode* head) {
      ListNode *slow = head;        
      ListNode *fast = head;
      while (fast!=nullptr && fast->next!=nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;        
    }
    ListNode* Middle(ListNode* head,ListNode* fast){
      if (fast==nullptr || fast->next==nullptr)
      {
        return head;
      }
      
      return Middle(head->next,fast->next->next);
    }
    ListNode* middleNode(ListNode* head) {
      ListNode* fast = head;
      return Middle(head,fast);
    }
};