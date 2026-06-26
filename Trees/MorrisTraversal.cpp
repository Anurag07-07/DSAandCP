#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data){
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

void Morris(TreeNode* root){
  TreeNode* curr = root;
  while (curr!=nullptr)
  {
    if (curr->left==nullptr)
    {
      cout<<curr->data<<" ";
      curr = curr->right;
    }else{
      //Find The Inorder Predessasor
      TreeNode* pred = curr->left;
      while (pred->right!=nullptr && pred->right!=curr)
      {
        pred = pred->right;
      }
      if (pred->right==nullptr)
      {
        pred->right = curr;
        curr = curr->left;
      }else{
        pred->right = nullptr;
        cout<<curr->data<<" ";
        curr = curr->right;
      }
    }
  }
}

void MorrisPreOrder(TreeNode* root){
  TreeNode* curr = root;
  while (curr!=nullptr)
  {
    if (curr->left==nullptr)
    {
      cout<<curr->data<<" ";
      curr = curr->right;
    }else{
      //Find The Inorder Predessasor
      TreeNode* pred = curr->left;
      while (pred->right!=nullptr && pred->right!=curr)
      {
        pred = pred->right;
      }
      if (pred->right==nullptr)
      {
        cout<<curr->data<<" ";
        pred->right = curr;
        curr = curr->left;
      }else{
        pred->right = nullptr;
        curr = curr->right;
      }
    }
  }
}

TreeNode* reverseFunction(TreeNode* start) {
  TreeNode* prev =nullptr;
  TreeNode* curr = start;
  TreeNode* next =nullptr;

  while (curr !=nullptr) {
    next = curr->right;
    curr->right = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

void printReversePairs(TreeNode* start,TreeNode* end){
  TreeNode* head = reverseFunction(start);
}

void MorrisTraversalPostOrder(TreeNode* root){
  TreeNode* dummy = new TreeNode(0);
  dummy->left = root;
  TreeNode* curr = dummy;
  while (!curr)
  {
    if (curr->left==nullptr)
    {
      curr = curr->right;
    }else{
        TreeNode* pred = curr;
        while (pred->right!=nullptr && pred->right!=curr)
        {
          pred = pred->right;
        }

        if (pred->right==nullptr)
        {
          pred->right = curr;
          curr = curr->left;
        }else{

        }
    }
  }
  
}

int main()
{
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  MorrisPreOrder(root);
  return 0;
}