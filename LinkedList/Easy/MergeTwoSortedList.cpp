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
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* dummy = new ListNode(0);
    //     ListNode* tail = dummy;
    //     while (list1 && list2)
    //     {
    //       if (list1->val<list2->val)
    //       {
    //         tail->next = list1;
    //         tail = tail->next;
    //         list1 = list1->next;
    //         tail->next = nullptr;
    //       }else{
    //         tail->next = list2;
    //         tail = tail->next;
    //         list2 = list2->next;
    //         tail->next = nullptr;
    //       }
          
    //     }

    //     if (list1)
    //     {
    //       tail->next = list1;
    //     }else{
    //       tail->next = list2;
    //     }
    //     return dummy->next;
    // }
    ListNode* Merging(ListNode* list1, ListNode* list2){
      //Base case => jaha koi logic lgane ki jarurat nahi hai
      //Matlab thinkki agar list1 kahli hui to list2 return and list2 khali hui to list1 return
      if (list1==nullptr)
      {
        return list2;
      }
      if (list2==nullptr)
      {
        return list1;
      }
      
      //Ab do List hai usme se current element hi compare ho sakta hai
      //To jo element hai wo node rakh ke baki list ko merge hone begh do
      //And Jab Merge hoke aaye list to to current node se merge kar dena
      //And Then List ko return kar do
      if (list1->val<list2->val)
      {
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
      }else{
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
      }
             
    } 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    }
};