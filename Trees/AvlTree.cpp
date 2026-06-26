#include<bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  int height;
  Node* right;
  Node* left;
  Node(int value){
    val = value;
    height = 1;
    left= right = nullptr;
  }
};


int getheight(Node* root){
  if (!root)
  {
    return 0;
  }
  return root->height;
}

int getbalance(Node* root){
  return getheight(root->left)-getheight(root->right);
}

//Right Rotation
Node* rightRotation(Node* root){
  
  Node* child = root->left;
  Node* childRight = child->right;
  child->right = root;
  root->left = childRight;
  
  //Update The Height
  root->height = 1+ max(getheight(root->left),getheight(root->right));
  child->height = 1+ max(getheight(child->left),getheight(child->right));
  return child;

}

Node* leftRotation(Node* root){
  Node* child = root->right;
  Node* childLeft = child->left;
  child->left = root;
  root->right = childLeft;

  root->height = 1+ max(getheight(root->left),getheight(root->right));
  child->height = 1+ max(getheight(child->left),getheight(child->right));
  return child;
}

Node* insert(Node* root,int key){
  //does not exist
  if (!root)
  {
    return new Node(key);
  }
  
  // exist
  if (key<root->val)
  {
   root->left =   insert(root->left,key);
  }else if(key>root->val){
    root->right = insert(root->right,key);
  }else{
    return root;
  }
  

  //Update the Height
  root->height = 1+ max(getheight(root->left),getheight(root->right));


  //Balance Check
  int balance = getbalance(root);

  //Left Left Case
  if (balance>1 && key<root->left->val)
  {
    return rightRotation(root);
  }
  
  //Right Right Case
  else if (balance< -1 && root->right->val<key)
  {
    return leftRotation(root);
  }
  
  //left Right Case
  else if (balance>1 && root->left->val<key)
  {
    root->left =  leftRotation(root->left);
    return rightRotation(root);
  }
  
  //Right left Case
  else if (balance<-1 && root->right->val>key)
  {
    root->right =  rightRotation(root->right);
    return leftRotation(root);
  }
  
  //No Unbalance
  else{
    return root;
  }
}




Node* deleteNode(Node* root,int key){
if (!root)
{
    return nullptr;
  }
  
  if (key<root->val)
  {
    root->left =  deleteNode(root->left,key);
  }else if(key>root->val){
    root->right =  deleteNode(root->right,key);
  }else
  {
    //Leaf Node
    if (!root->left && !root->right)
    {
      delete root;
      return nullptr;
    }
    
    ///Only One Child
    else if (root->left&&!root->right)
    {
      Node*temp = root->left;
      delete root;
      return temp;
    }else if (!root->left&& root->right)
    {
      Node*temp = root->right;
      delete root;
      return temp;
    }
    //Both Child Exist
    else{
      //Right Side Smallest Element
      Node* curr  = root->right;
      while (curr->left)
      {
        curr = curr->left;
      }

      root->val = curr->val;
      root->right =  deleteNode(root->right,curr->val);
    }      
  }
  //Update the Height
  root->height = 1+max(getheight(root->left),getheight(root->right));

  //Check the Balance
  int balance = getbalance(root);
  //Left Side
  if (balance>1)
  {
    //Left Left
    if (getbalance(root->left)>=0)
    {
     return rightRotation(root);
    }else{
      //Left Right
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }else if (balance<-1)
  {
    //Right Right 
    if (getbalance(root->right)<=0)
    {
     return leftRotation(root);
    }else{
      //right Left
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }else{
    return root;
  }
}


void PreOrderIterative(Node* root){
  vector<int> ans;
  if(root==nullptr) return;

  stack<Node*> st;
  st.push(root);
  while (!st.empty())
  {
    Node* temp = st.top();
    st.pop();

    ans.push_back(temp->val);

    if (temp->right)
    {
      st.push(temp->right);
    }

    if (temp->left)
    {
      st.push(temp->left);
    }
    
  }

  for(int x:ans){
    cout<<x<<" ";
  }
  
}

void InOrderIterative(Node* root){
  vector<int> ans;
  if(root==nullptr) return;

  stack<Node*> st;
  Node* curr = root;
  while (!curr || !st.empty())
  {
    while (!curr)
    {
      st.push(curr);
      curr = curr->left;
    }

    curr = st.top();
    st.pop();

    ans.push_back(curr->val);
    
    curr = curr->right;
  }

  for(int x:ans){
    cout<<x<<" ";
  }
}


void VerticalOrderTraversal(Node* root){
  vector<int> ans;
  if (root==nullptr)
  {
    return;
  }
  
  queue<pair<Node*,int>> q;
  map<int,vector<int>> mp;
  q.push(make_pair(root,0));
  while (!q.empty())
  {
    pair<Node*,int> temp = q.front();
    int elem = temp.first->val;
    int idx = temp.second;
    q.pop();
    mp[idx].push_back(elem);

    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,idx-1));
    }

    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,idx+1));
    }
  }

  for(auto &i:mp){
    vector<int> a = i.second;
    for(int y:a){
      ans.push_back(y);
    }
  }


  for(int x:ans){
    cout<<x<<" ";
  }
  
}

int Height(Node* root){
  if (!root)
  {
    return 0;
  }
  return 1+max(Height(root->left),Height(root->right));
}

void VerticalOrderTraversal1(Node* root){
  vector<int> ans;
  if (root==nullptr)
  {
    return;
  }

  //Find the max horizontal distance
  int n = Height(root);
  vector<vector<int>> index(2*n+1);
  int maxlen = INT_MIN;
  int minlen = INT_MAX;

  queue<pair<Node*,int>> q;
  q.push(make_pair(root,0));
  while (!q.empty())
  {
    pair<Node*,int> temp = q.front();
    int elem = temp.first->val;
    int idx = temp.second;

    maxlen = max(maxlen,idx);
    minlen = min(minlen,idx);

    q.pop();
    index[n+idx].push_back(elem);

    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,idx-1));
    }

    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,idx+1));
    }
  }

  for (int i = minlen; i <= maxlen; i++)
  {
    for (int j = 0; j < index[i+n].size(); j++)
    {
      cout<<index[i+n][j]<<" ";
      // ans.push_back(index[i+n][j]);
    }

  }

  for(int x:ans){
    cout<<x<<" ";
  }
  
}

void PostOrderTraversal(Node* root){
  vector<int> ans;
  if(root==nullptr) return;
  
  stack<Node*> st1;
  stack<int> st2;
  st1.push(root);
  while (!st1.empty())
  {
    Node* temp = st1.top();
    st1.pop();
    st2.push(temp->val);

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
    ans.push_back(st2.top());
    st2.pop();
  }

  for(int x:ans){
    cout<<x<<" ";
  }
  
}

void DiagonalOrderTraversal(Node* root){
  vector<int> ans;
  if (root==nullptr) return;

  int D = 0;
  queue<pair<Node*,int>> q;
  q.push(make_pair(root,D));

  map<int,vector<int>> mp;
  while (!q.empty())
  {
    //Find the Element
    pair<Node*,int> temp = q.front();
    q.pop();

    int elem = temp.first->val;
    int diagonal = temp.second;

    mp[diagonal].push_back(elem);

    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left,D+1));
    }

    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right,D));
    }
    
  }


  for(auto &i:mp){
    vector<int> a = i.second;
    for(int y:a){
      ans.push_back(y);
    }
  }


  for(int x:ans){
    cout<<x<<" ";
  }
}

void LeftTraverse(Node* root,vector<int>& ans){
  if (root==nullptr)
  {
    return;
  }
  
  if (root->left==nullptr && root->right==nullptr)
  {
    return;
  }

  //Push the Element
  ans.push_back(root->val);
  if (root->left)
  {
    ReverseRight(root->left,ans);
  }else{
    ReverseRight(root->right,ans);
  }
}

void LeafTraversal(Node* root,vector<int>& ans){
  if (root==nullptr)
  {
    return;
  }
  
  if (root->left==nullptr && root->right==nullptr)
  {
    ans.push_back(root->val);
    return;
  }
  
  LeafTraversal(root->left,ans);
  LeafTraversal(root->right,ans);
}

void ReverseRight(Node* root,vector<int>& ans){
  if (root==nullptr)
  {
    return;
  }

  if (root->left==nullptr && root->right==nullptr)
  {
    return;
  }

  if (root->left)
  {
    ReverseRight(root->left,ans);
  }else{
    ReverseRight(root->right,ans);
  }
  ans.push_back(root->val);
}


void BoundaryTraversal(Node* root){
  vector<int> ans;
  LeftTraverse(root,ans);
  LeafTraversal(root,ans);
  ReverseRight(root->right,ans);
  for(int x:ans){
    cout<<x<<" ";
  }
}


int main()
{
  //Duplicate are not allowed
  Node* root = nullptr;
  root = insert(root,10);
  root = insert(root,20);
  root = insert(root,30);
  root = insert(root,50);
  root = insert(root,70);
  root = insert(root,5);
  root = insert(root,100);
  root = insert(root,95);
  root = deleteNode(root,95);

  // InOrderIterative(root);
  // PostOrderTraversal(root);
  // cout<<endl;
  // VerticalOrderTraversal1(root);
  // DiagonalOrderTraversal(root);
  BoundaryTraversal(root);
  return 0;
}


