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
  PostOrderTraversal(root);
  return 0;
}
