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
    bool isPalindrome(ListNode* head) {
        if (head->next==nullptr)
        {
          return true;
        }
        
        int count  = 0;
        ListNode* temp = head;
        while (temp)
        {
          count++;
          temp = temp->next;
        }

        count = count/2;
        ListNode* curr1 = head;
        ListNode* curr2 = nullptr;
        ListNode* temp1 = head;
        while (count!=1)
        {
          temp1 = temp1->next;
          count--;
        }
        curr2 = temp1->next;
        temp1->next = nullptr;

        //Reverse
        ListNode* curr = curr2;
        ListNode* future = nullptr;
        ListNode* prev = nullptr;
        while (curr)
        {
          future = curr->next;
          curr->next = prev;
          prev = curr;
          curr = future;
        }
        
        //Compare
        curr2 = prev;
        while (curr1 && curr2)
        {
          if (curr1->val!=curr2->val)
          {
            return false;
          }
          curr1 = curr1->next;
          curr2 = curr2->next;
        }
        return true;
    }
    
    public:
    ListNode* left;
    bool check(ListNode* head){
      //base Case => Hamesha Single Element ya null Palindrone hota hai
      if (head==nullptr)
      {
        return true;
      }
      
      bool KyaCurrentkoChorkarbakibachilistPalindroneHai = check(head->next);
      if (!KyaCurrentkoChorkarbakibachilistPalindroneHai)
      {
        return false;
      }
      
      // Jab base Case ne bol diya ki main to palidrone hu to ab ek ek element
      //Compare honge jab head back track karega
      bool MatchHorahe = left->val==head->val;
      
      //Left ko Aage badha do
      left = left->next;

      //To ye ek Subset ka Part hai to return karega ki main palidrone hu ki nahi
      return MatchHorahe;
    }
    bool isPalindrome(ListNode* head) {
      left = head;
      return check(head);
    }
};