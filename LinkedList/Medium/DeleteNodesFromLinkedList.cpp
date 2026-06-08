#include<bits/stdc++.h>
using namespace std;

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
  ListNode(int val){
    this->val = val;
    next = nullptr;
  }
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        unordered_set<int> s(nums.begin(),nums.end());
        while (temp!=nullptr)
        {
          if (!s.count(temp->val))
          {
            ans.push_back(temp->val);
          }
          
          temp = temp->next;
        }

        //Create New List
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        curr->next = new ListNode(ans[0]);
        curr = curr->next;
        for (int i = 1; i < ans.size(); i++)
        {
          curr->next  = new ListNode(ans[i]);
          curr = curr->next;
        }
        curr->next = nullptr;
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* NewList(ListNode* head,unordered_set<int>& s){
      if (head==nullptr)
      {
        return head;
      }

      if (!s.count(head->val))
      {
        //Aage Ki List Zoro and Current Element ko return kar do
        head->next = NewList(head->next,s);
        return head;
      }else{
        return NewList(head->next,s);
      }

    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      unordered_set<int> s(nums.begin(),nums.end());
      return NewList(head,s);
    }
};

int main(int argc, char const *argv[])
{
  return 0;
}
