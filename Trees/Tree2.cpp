#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data){
    this->val = data;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> LeftViewIterative(TreeNode* root){
  queue<TreeNode*> q;
  vector<int> ans;

  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    int counter = size;
    for (int i = 0; i < size; i++)
    {
      TreeNode* temp = q.front();
      if (counter==size)
      {
        ans.push_back(temp->val);
      }
      counter--;
      q.pop();

      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
      
    }
    
  }
  return ans;
}

vector<int> RightViewIterative(TreeNode* root){
  queue<TreeNode*> q;
  vector<int> ans;

  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    int counter = size;
    for (int i = 0; i < size; i++)
    {
      TreeNode* temp = q.front();
      counter--;
      if (counter==0)
      {
        ans.push_back(temp->val);
      }
      q.pop();

      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
      
    }
    
  }
  return ans;
}

void LeftViewRecursive(TreeNode* root,int level,vector<int>& ans){
  if (root==nullptr)
  {
    return;
  }

  if (level==ans.size())
  {
    ans.push_back(root->val);
  }
  
  LeftViewRecursive(root->left,level+1,ans);
  LeftViewRecursive(root->right,level+1,ans);
}

void RightViewRecursive(TreeNode* root,int level,vector<int>& ans){
  if (root==nullptr)
  {
    return;
  }

  if (level==ans.size())
  {
    ans.push_back(root->val);
  }
  
  RightViewRecursive(root->right,level+1,ans);
  RightViewRecursive(root->left,level+1,ans);
}

vector<int> TopView(TreeNode* root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }

  queue<pair<TreeNode*,int>> q;
  map<int,int> index;
  q.push(make_pair(root,0));

  while (!q.empty())
  {
    //Find the Topmost Element
    pair<TreeNode*,int>  temp = q.front();
    q.pop();

    if (!index.count(temp.second))
    {
      index[temp.second] = temp.first->val;
    }

    
    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,temp.second-1));
    }
    
    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,temp.second+1));
    }
    
  }


  for(auto &i:index){
    ans.push_back(i.second);
  }
  
  return ans;
}

vector<int> BottomView(TreeNode* root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }

  queue<pair<TreeNode*,int>> q;
  map<int,int> index;
  q.push(make_pair(root,0));

  while (!q.empty())
  {
    //Find the Topmost Element
    pair<TreeNode*,int>  temp = q.front();
    q.pop();

    index[temp.second] = temp.first->val;

    
    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,temp.second-1));
    }
    
    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,temp.second+1));
    }
    
  }


  for(auto &i:index){
    ans.push_back(i.second);
  }
  
  return ans;
}

int LeftSize(TreeNode* root){
  if (!root)
  {
    return 0;
  }

  if (root->left==nullptr && root->right==nullptr)
  {
    return 1;
  }
  
  return 1+LeftSize(root->left);
}

vector<int> TopViewArray(TreeNode* root){
  int n =  LeftSize(root);
  vector<int> ans;
  if (!root)
  {
    return ans;
  }


  queue<pair<TreeNode*,int>> q;
  vector<int> index(2*n+1,-1);
  q.push(make_pair(root,0));

  while (!q.empty())
  {
    //Find the Topmost Element
    pair<TreeNode*,int>  temp = q.front();
    q.pop();

    if (index[temp.second+n]==-1)
    {
      index[temp.second+n] = temp.first->val;
    }
    

    
    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,temp.second-1));
    }
    
    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,temp.second+1));
    }
    
  }


  for(int x:index){
    if (x!=-1)
    {
      ans.push_back(x);
    }
  }
  
  return ans;
}

vector<int> BottomViewArray(TreeNode* root){
  int n =  LeftSize(root);
  vector<int> ans;
  if (!root)
  {
    return ans;
  }


  queue<pair<TreeNode*,int>> q;
  vector<int> index(2*n+1,-1);
  q.push(make_pair(root,0));

  int max_cord = 0;
  int min_cord = 0;

  while (!q.empty())
  {
    //Find the Topmost Element
    pair<TreeNode*,int>  temp = q.front();
    q.pop();
    
    max_cord = max(max_cord,temp.second);
    min_cord = min(min_cord,temp.second);
    
    index[temp.second+n] = temp.first->val;
    
    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,temp.second-1));
    }
    
    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,temp.second+1));
    }
    
  }

  for (int i = min_cord; i <= max_cord; i++)
  {
    ans.push_back(index[i+n]);
  }
  
  
  return ans;
}

int main()
{
   TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
  //Left View
  // vector<int> ans = RightViewIterative(root);
  // vector<int> ans;
  // RightViewRecursive(root,0,ans);
  // for(int x:ans){
  //   cout<<x<<" ";
  // }
  
  vector<int> ans = BottomViewArray(root);
  
  for(int x:ans){
    cout<<x<<" ";
  }

  return 0;
}
