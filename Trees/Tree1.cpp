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

void Traversal(TreeNode* t){
  if (t==nullptr)
  {
    return;
  }

  Traversal(t->left);
  cout<<t->data<<" ";
  Traversal(t->right);
}

void PreOrderIterative(TreeNode* root){
  stack<TreeNode*> st;
  st.push(root);
  while (!st.empty())
  {
    TreeNode* temp = st.top();
    st.pop();

    cout<<temp->data<<" ";
    if (temp->right)
    {
      st.push(temp->right);
    }

    if (temp->left)
    {
      st.push(temp->left);
    }
  }
}

void InOrderIterative(TreeNode* root){
  stack<TreeNode*> st;
  TreeNode* temp = root;
  while (temp&&!st.empty())
  {
    while (temp)
    {
      st.push(temp);
      temp = temp->left;
    }

    //When Reaches last Node
    temp = st.top();
    st.pop();

    cout<<temp->data<<" ";
    temp = temp->right;
  }

}

void PreOrderRecursive(TreeNode* root){
  if (!root)
  {
    return;
  }

  cout<<root->data<<" ";
  PreOrderRecursive(root->left);
  PreOrderRecursive(root->right);
}

void InOrderRecursive(TreeNode* root){
  if (!root)
  {
    return;
  }

  InOrderIterative(root->left);
  cout<<root->data<<" ";
  InOrderIterative(root->right);
}

void LevelOrderTraversal(TreeNode* root){
  if(root==nullptr) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    { 
      TreeNode* temp = q.front();
      q.pop();
      
      cout<<temp->data<<" ";
      if (temp->left)
      {
        q.push(temp->left);
      }
      
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
    cout<<endl;
  }
}

void PostOrderItertive(TreeNode* root){
  stack<TreeNode*> st1;  
  stack<TreeNode*> st2;
  
  st1.push(root);
  while (!st1.empty())
  {
    TreeNode* temp = st1.top();
    st1.pop();

    st2.push(temp);

    if (temp->left)
    {
      st1.push(temp->left);
    }

    if (temp->right)
    {
      st1.push(temp->right);
    }
  }

  while (!st2.empty())
  {
    cout<<st2.top()->data<<" ";
    st2.pop();
  }
}

void PostOrderRecursive(TreeNode* root){
  if (!root)
  {
    return;
  }

  PostOrderRecursive(root->left);
  PostOrderRecursive(root->right);
  cout<<root->data<<" ";
}

//Recusrsive Level Order Traversal
int TreeHeight(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }

  //Find The Left Height
  int leftHeight = TreeHeight(root->left);
  int rightHeight = TreeHeight(root->right);
  
  return 1+max(leftHeight,rightHeight);
}

//Apply Level Order Traversal
void RecursiveLevelOrder(TreeNode* root,int level){
  if (root==nullptr)
  {
    return;
  }

  if (level == 1)
  {
    cout<<root->data<<" ";
  }

  //Other Wise Print the Left and Right Node
  RecursiveLevelOrder(root->left,level-1);
  RecursiveLevelOrder(root->right,level-1);
}

void HeightTraversal(TreeNode* root){
  int height = TreeHeight(root);
  for (int i = 1; i <= height; i++)
  {
    RecursiveLevelOrder(root,i);
    cout<<endl;
  }
}

int SizeofTree(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }

  return 1+SizeofTree(root->left)+SizeofTree(root->right);
}

int Sum(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }
  return root->data+Sum(root->left)+Sum(root->right);
}

int SizeofTree1(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  int count = 0;
  while (!q.empty())
  {
    TreeNode* temp = q.front();
    q.pop();
    count++;

    if (temp->left)
    {
      q.push(temp->left);
    }

    if (temp->right)
    {
      q.push(temp->right);
    }
    
  }
  return count;
}

int LeaveNode(TreeNode* root){
  if (!root)
  {
    return 0;
  }

  if (root->left==nullptr && root->right==nullptr)
  {
    return 1;
  }

  int left = LeaveNode(root->left);
  int right = LeaveNode(root->right);
  
  return left+right;
}

int LeaveNodeIterative(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  int total = 0;
  while (!q.empty())
  { 
    TreeNode* temp = q.front();
    q.pop();

    if (temp->right==nullptr && temp->left==nullptr)
    {
      total++;
    }

    if (temp->left)
    {
      q.push(temp->left);
    }

    if (temp->right)
    {
      q.push(temp->right);
    }

  }
  return total;
}

int TotalNode(TreeNode* root){
  if (!root)
  {
    return 0;
  }
  return 1+TotalNode(root->left)+TotalNode(root->right);
}

int LeafNode(TreeNode* root){
  if (!root)
  {
    return 0;
  }

  if (!root->left && !root->right)
  {
    return 1;
  }
  
  int left = LeafNode(root->left);
  int right = LeafNode(root->right);

  return left+right;
}

int NonLeafNode(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }

  if (root->left==nullptr && root->right==nullptr)
  {
    return 0;
  }

  int left = NonLeafNode(root->left);
  int right = NonLeafNode(root->right);
  
  return 1+left+right;
}

int TotalNonLeaves(TreeNode* root){
  //Find the Total Node
  return NonLeafNode(root);
}

int TotalNonLeafNode(TreeNode* root){
  int count = 0;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty())
  {   
    TreeNode* temp = q.front();
    q.pop();

    if (temp->left!=nullptr || temp->right!=nullptr)
    {
      count++;
    }

    if (temp->left)
    {
      q.push(temp->left);
    }

    if (temp->right)
    {
      q.push(temp->right);
    }
  }

  return count;
}


int Height(TreeNode* root){
  if (!root)
  {
    return 0;
  }
  return 1+Height(root->left)+Height(root->right);
}

int HeightLevelOrder(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  int height = 0;
  while (!q.empty())
  {
    height++;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode* temp = q.front();
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
  return height;
}

void MaxAtLevel(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);

  vector<int> ans;
  while (!q.empty())
  {
    int size = q.size();
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
      TreeNode* temp = q.front();
      q.pop();
      maxi =max(maxi,temp->data);
      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
    ans.push_back(maxi);
  }
  
  for(int x:ans){
    cout<<x<<" ";
  }
}

bool CheckIdentical1(TreeNode* root1 , TreeNode* root2){
  if (root1==nullptr || root2==nullptr)
  {
    return false;
  }

  if (root1==nullptr&&root2==nullptr)
  {
   return true; 
  }

  if (root1->data!=root2->data)
  {
    return false;
  }
  
  bool leftCheck = CheckIdentical1(root1->left,root2->left);
  bool rightCheck = CheckIdentical1(root1->right,root2->right);
  
  return leftCheck&&rightCheck;
}

bool CheckIdentical(TreeNode* root1 , TreeNode* root2){
  queue<pair<TreeNode*,TreeNode*>> q;
  q.push(make_pair(root1,root2));

  while (!q.empty())
  {
    pair<TreeNode*,TreeNode*> temp = q.front();
    q.pop();

    if (temp.first==temp.second)
    {
      continue;
    }
    

    if (temp.first==nullptr || temp.second==nullptr)
    {
      return false;
    }

    if (temp.first->data!=temp.second->data)
    {
      return false;
    }
    
    q.push(make_pair(temp.first->left,temp.second->left));
    q.push(make_pair(temp.first->right,temp.second->right));
    
  }



  return true;
}



int HeightofBalance(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }
  return 1 + max(Height(root->left),Height(root->right));
}


bool isBalanced(TreeNode* root) {
  int left = HeightofBalance(root->left);
  int right = HeightofBalance(root->right);

  if (abs(left-right)>=2)
  {
    return false;
  }
  return true;
}


int isBalancedTree(TreeNode* root){
  if (root==nullptr)
  {
    return 0;
  }
  
  //Find the Left Height
  int leftHeight = isBalancedTree(root->left);
  if (leftHeight==-1)
  {
    return -1;
  }

  int rightHeight = isBalancedTree(root->right);
  if (rightHeight==-1)
  {
    return -1;
  }
  
  if (abs(leftHeight-rightHeight)<=1)
  {
    return max(leftHeight,rightHeight)+1;
  }

  return -1;
}

void SpiralTraversal(TreeNode* root){
  stack<TreeNode*> st1;
  stack<TreeNode*> st2;
  st1.push(root);
  int level = 0;
  vector<vector<int>> ans;

  while (!st1.empty() || !st2.empty())
  {
    int size = level%2==0 ? st1.size() : st2.size();
    vector<int> a;
    if (level%2==0)
    {
      for (int i = 0; i < size; i++)
      {
        TreeNode* temp = st1.top();
        st1.pop();
        a.push_back(temp->data);
        if (temp->left)
        {
          st2.push(temp->left);
        }

        if (temp->right)
        {
          st2.push(temp->right);
        }
        
      }
      ans.push_back(a);
      
    }else{
      for (int i = 0; i < size; i++){
        TreeNode* temp = st2.top();
      st2.pop();
      a.push_back(temp->data);
      if (temp->right)
      {
        st1.push(temp->right);
      }

      if (temp->left)
      {
        st1.push(temp->left);
      }
      }
      ans.push_back(a);
    }
    level++;
  }

  for(vector<int> x:ans){
    for(int y:x){
      cout<<y<<" ";
    }
    cout<<endl;
  }
}

bool isCousins(TreeNode* root,int x,int y){
  if (!root)
  {
    return false;
  }

    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty())
    {
      int size = q.size();
      bool Foundx = false;
      bool Foundy = false;
      for (int i = 0; i < size; i++)
      {
        TreeNode* temp = q.front();
        q.pop();

        if (temp->data==x)
          Foundx =true;
        if (temp->data==y)
          Foundy =true;
        
        //Check for Sibling
        if (temp->left!=nullptr && temp->right!=nullptr)
        {
          if ((temp->left->data==x && temp->right->data==y) || (temp->left->data==y && temp->right->data==x))
          {
            return false;
          }
          
        }

        if (temp->left)
        {
          q.push(temp->left);
        }

        if (temp->right)
        {
          q.push(temp->right);
        }
        

      }


      if (Foundx&&Foundy)
      {
        return true;
      }

      if (Foundx || Foundy)
      {
        return false;
      }
    }
    return false;    
}

vector<int> LeftView(TreeNode* root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }
  
  queue<TreeNode*> q;
  ans.push_back(root->data);
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    int counter = size;
    for (int i = 0; i < size; i++)
    {
      TreeNode * temp = q.front();
      if (counter==size)
      {
        ans.push_back(temp->data);
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

vector<int> RightView(TreeNode* root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }
  
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    int counter = size;
    for (int i = 0; i < size; i++)
    {
      TreeNode * temp = q.front();
      counter--;
      if (counter==0)
      {
        ans.push_back(temp->data);
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


void LeftViewRecursive(TreeNode* root,vector<int>& ans,int level){
  if (root==nullptr)
  {
    return;
  }

  if (level==ans.size())
  {
    ans.push_back(root->data);
  }
  
  LeftViewRecursive(root->left,ans,level+1);
  LeftViewRecursive(root->right,ans,level+1);
}

void RightViewRecursive(TreeNode* root,vector<int>& ans,int level){
  if (root==nullptr)
  {
    return;
  }

  if (level==ans.size())
  {
    ans.push_back(root->data);
  }
  
  RightViewRecursive(root->right,ans,level+1);
  RightViewRecursive(root->left,ans,level+1);
}


int main()
{
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Traversal(t1);
  // PreOrderIterative(root);
  // cout<<endl;
  // PreOrderRecursive(root);
  // cout<<endl;
  // InOrderIterative(root);
  // cout<<endl;
  // PostOrderItertive(root);
  // cout<<endl;
  // LevelOrderTraversal(root);
  // HeightTraversal(root);
  // cout<<SizeofTree(root)<<endl;
  // cout<<LeaveNode(root)<<endl;
  // cout<<TotalNonLeaves(root)<<endl;
  // cout<<HeightLevelOrder(root)<<endl;
  // MaxAtLevel(root);
  // SpiralTraversal(root);
  // vector<int> ans;
  // LeftViewRecursive(root,ans,0);
  
  for(int x:RightView(root)){
    cout<<x<<" ";
  }

  return 0;
}