#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* right;
  Node* left;
  Node(int val){
    this->data = val;
    right = nullptr;
    left = nullptr;
  }
};

//Recursive Tree Creation

Node* CreateTreeRecursive(){
  int n;cin>>n;
  if (n==-1)
  {
    return nullptr;
  }
  Node* temp = new Node(n);
  temp->left = CreateTreeRecursive();
  temp->right = CreateTreeRecursive();
  return temp;  
}

//Create a Tree
Node* CreateTree(){
  queue<Node*> q;
  //Make the root
  int x;cin>>x;
  Node* root = new Node(x);
  q.push(root);

  int first;
  int second;
  while (!q.empty())
  {
    //Find The Node
    Node* temp = q.front();
    q.pop();
    //Create Left Node
    cin>>first;
    if (first!=-1)
    {
      //Make new Node and connect with Root
      temp->left = new Node(first);
      q.push(temp->left);
    }

    cin>>second;
    if (second!=-1)
    {
      //Make new Node and connect with Root
      temp->right = new Node(second);
      q.push(temp->right);
    }
  }
  
  return root;
}

void PreOrder(Node* root){
  if (root==nullptr)
  {
    return;
  }
  
  cout<<root->data<<" ";
  PreOrder(root->left);
  PreOrder(root->right);
}

void InOrder(Node* root){
  if (root==nullptr)
  {
    return;
  }
  
  InOrder(root->left);
  cout<<root->data<<" ";
  InOrder(root->right);
}
void PostOrder(Node* root){
  if (root==nullptr)
  {
    return;
  }
  
  PostOrder(root->left);
  PostOrder(root->right);
  cout<<root->data<<" ";
}

int main(int argc, char const *argv[])
{
  Node* tree1 = CreateTreeRecursive();
  PostOrder(tree1);
  return 0;
}
