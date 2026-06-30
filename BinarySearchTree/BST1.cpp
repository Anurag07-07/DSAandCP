#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val){
    this->val = val;
    left = right = nullptr;
  }
};

class BST{
  public:
  TreeNode* Insert(TreeNode* root,int val){
    if (root==nullptr)
    {
      return new TreeNode(val);
    }

    if (root->val>val)
    {
      root->left = Insert(root->left,val);
    }else{
      root->right = Insert(root->right,val);
    }
    return root;
  }

  TreeNode* Search(TreeNode* root,int val){
      TreeNode* curr = root;
      while (curr)
      {
        if (curr->val==val)
        {
          return curr;
        }else if (curr->val>val)
        {
          curr = curr->left;
        }else{
          curr = curr->right;
        }
      }
      return nullptr;
  }

  TreeNode* DeleteNode(TreeNode* root,int val){
    if(root==nullptr) return nullptr;

    //Searching
    if (root->val>val)
    {
      root->left = DeleteNode(root->left,val);
    }else if (root->val<val)
    {
      root->right = DeleteNode(root->right,val);
    }else{
      if (root->left==nullptr)
      {
        TreeNode* temp = root->right;
        delete root;
        return temp;
      } else if (root->right==nullptr)
      {
        TreeNode* temp  = root->left;
        delete root;
        return temp;
      }
      
      //If Both The Child Were Present
      //First Find the Inorder Successor
      TreeNode* curr = root->right;
      while (curr&&curr->left!=nullptr)
      {
        curr = curr->left;
      }

      root->val = curr->val;

      //Delete taht Inorder Node and Connect that subtree with root tree
      root->right =  DeleteNode(root->right,curr->val); 
    }
    return root;
  }

  void Inorder(TreeNode* root) {
    if (root == nullptr) return;
    Inorder(root->left);
    cout << root->val <<" ";
    Inorder(root->right);
  }

  bool CheckBST(TreeNode* root,long long minVal,long long maxVal){
    if (root==nullptr)
    {
      return true;
    }
    
    if (root->val<=minVal || root->val>=maxVal)
    {
      return false;
    }
    
    return CheckBST(root->left,minVal,root->val)&&CheckBST(root->right,root->val,maxVal);
  }

  bool CheckPreorder(vector<int>& preorder){
    stack<int> st;
    int root_value = INT_MAX;
    for(int x:preorder){
      if (root_value<x)
      {
        return false;
      }
      
      while (!st.empty() && st.top()<x)
      {
        root_value = st.top();
        st.pop();
      }
      st.push(x);
    }
    return true;
  }
};

int main() {
    BST tree;
    TreeNode* root = nullptr;

    // 1. Insertion Test
    root = tree.Insert(root, 50);
    tree.Insert(root, 30);
    tree.Insert(root, 20);
    tree.Insert(root, 40);
    tree.Insert(root, 70);
    tree.Insert(root, 60);
    tree.Insert(root, 80);

    cout << "Inorder Traversal (Sorted Output): ";
    tree.Inorder(root);
    cout << "\n\n";

    // 2. Search Test
    int key = 40;
    if (tree.Search(root, key) != nullptr) {
        cout << key << " Tree mein mil gaya! \n";
    } else {
        cout << key << " Tree mein nahi hai! \n";
    }
    cout << "\n";

    // 3. Check BST Test
    if (tree.CheckBST(root)) {
        cout << "Haan bhai, ye ek valid BST hai. \n";
    } else {
        cout << "Nahi, ye BST nahi hai! \n";
    }
    cout << "\n";

    // 4. Deletion Test
    cout << "Node 50 ko delete kar rahe hain (Root with 2 children)...\n";
    root = tree.DeleteNode(root, 50);
    
    cout << "Delete karne ke baad Inorder Traversal: ";
    tree.Inorder(root);
    cout << "\n";

    return 0;
}