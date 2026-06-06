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
    int getDecimalValue(ListNode* head) {
      //Reverse the List 
      ListNode* prev = nullptr;        
      ListNode* next = nullptr;        
      ListNode* curr = head;
      while (curr!=nullptr)
      {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      head = prev; 
      
      ListNode* temp = head;
      int pow = 1;
      int ans  = 0;
      while (temp!=nullptr)
      {
        int value = temp->val;
        ans += value*pow;
        pow = pow*2;
        temp = temp->next;
      }
      return ans;
    }
};