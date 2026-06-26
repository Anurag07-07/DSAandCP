#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data){
    this->data = data;
    left = right = nullptr;
  }
};

void PreOrderTraversal(TreeNode* root){
  if (root==nullptr)
  {
    return;
  }
  PreOrderTraversal(root->left);
  cout<<root->data<<" ";
  PreOrderTraversal(root->right);
}

TreeNode* buildTreeHelper(vector<int>& postorder,vector<int>& inorder,int& idx,int inorder_start,int inorder_end,unordered_map<int,int>& mp){
  if (inorder_start>inorder_end)
  {
    return nullptr;
  }

  //Create a tree
  int value = postorder[idx];
  TreeNode* root = new TreeNode(value);
  idx--;

  //Create Right Subtree 
  //For That Find the Index of current elment
  int index = mp[value];
  root->right = buildTreeHelper(postorder,inorder,idx,index+1,inorder_end,mp);
  root->left = buildTreeHelper(postorder,inorder,idx,inorder_start,index-1,mp);
  return root;
}

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
  unordered_map<int,int> mp;

  for (int i = 0; i < inorder.size(); i++)
  {
    mp[inorder[i]] =  i;
  }

  int n = inorder.size();

  int index = n-1;
  
  TreeNode* root =  buildTreeHelper(postorder,inorder,index,0,n-1,mp);
  return root;
}





int main(int argc, char const *argv[])
{
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
  TreeNode* root =  buildTree(inorder,postorder);
  PreOrderTraversal(root);
  return 0;
}
