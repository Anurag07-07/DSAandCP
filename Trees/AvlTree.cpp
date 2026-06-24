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


void PreOrderRecursive(Node* root){
  if (!root)
  {
    return;
  }

  PreOrderRecursive(root->left);
  cout<<root->val<<" ";
  PreOrderRecursive(root->right);
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

  PreOrderRecursive(root);
  return 0;
}
