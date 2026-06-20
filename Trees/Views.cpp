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

vector<int> LeftViewQueue(Node*  root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }
  
  queue<Node*> q;
  q.push(root);
  while (!q.empty())
  {
    int n = q.size();
    ans.push_back(q.front()->data);
    while (n--)
    {
      Node *temp = q.front();
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

void LView(Node* root,int level,vector<int> & ans){

  if (!root)
  {
    return;
  }

  //agar node jyada ha iska matlab different node hai hai and iske pehle same level par aur node aa chuke hai 

  if (level==ans.size())
  {
    ans.push_back(root->data);
  }


  LView(root->left,level+1,ans);
  LView(root->right,level+1,ans);
}

void RView(Node* root,int level,vector<int> & ans){

  if (!root)
  {
    return;
  }

  //agar node jyada ha iska matlab different node hai hai and iske pehle same level par aur node aa chuke hai 

  if (level==ans.size())
  {
    ans.push_back(root->data);
  }


  RView(root->right,level+1,ans);
  RView(root->left,level+1,ans);
}


vector<int> RightView(Node* root){
  vector<int> ans;
  if (!root)
  {
    return ans;
  }
  
  queue<Node*> q;
  q.push(root);
  while (!q.empty())
  {
    int n = q.size();
    ans.push_back(q.front()->data);
    while (n--)
    {
      Node *temp = q.front();
      q.pop();
      if (temp->right)
      {
        q.push(temp->right);
      }
      if (temp->left)
      {
        q.push(temp->left);
      }

    }
  }
  return ans;
}

//Find Leftmost element position
//Find Rightmost element position
//Create Array with size right-left+1 
void Find(Node* root,int pos,int &l,int &r){
  if (root==nullptr)
  {
    return;
  }
  //Leftmost value 
  l  = min(l,pos);
  //Rightmost value 
  r  = max(r,pos);

  Find(root->left,pos-1,l,r);
  Find(root->right,pos+1,l,r);
}

vector<int> TopView(Node* root){
  int l = 0,r = 0;
  //Find Lmax and Rmax
  Find(root,0,l,r);
  vector<int> ans(r-l+1);
  vector<bool> filled(r-l+1,0);

  // We want two queue one for value one for index
  queue<Node*> elem;
  queue<int> index;
  elem.push(root);
  index.push(-1*l);
  while (!elem.empty())
  {
    //Take the Element
    Node* temp = elem.front();
    elem.pop();
    //Take the Index
    int pos = index.front();
    index.pop();

    //Insert the Elment at pos
    if (!filled[pos])
    {
      filled[pos] = 1;
      ans[pos] = temp->data;
    }
    
    if (temp->left)
    {
      elem.push(temp->left);
      index.push(pos-1);
    }

    if (temp->right)
    {
      elem.push(temp->right);
      index.push(pos+1);
    }
  }
  return ans;
  
}

void Tview(Node* root,int pos,vector<int>& ans,vector<int>& level,int l){
  
  if (root==nullptr)
  {
    return;
  }
  

  if (level[pos]>l)
  {
    ans[pos] = root->data;
    level[pos] = l;
  }
  
  Tview(root->left,pos-1,ans,level,l+1);
  Tview(root->right,pos+1,ans,level,l+1);
}

vector<int> TopViewRecursiveWay(Node* root){
  //Element with low level can be filled
  //So we intialized level array with INT_MAX  

  int l = 0,r = 0;
  //Find Lmax and Rmax
  Find(root,0,l,r);
  vector<int> ans(r-l+1);
  vector<int> level(r-l+1,INT_MAX);
  Tview(root,-1*l,ans,level,0);

  return ans;

}




int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
