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

void InOrderRecursive(TreeNode* root,vector<int>& ans){
  if (!root)
  {
    return;
  }

  InOrderRecursive(root->left,ans);
  ans.push_back(root->data);
  InOrderRecursive(root->right,ans);
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

void PostOrderRecursive(TreeNode* root,vector<int>& ans,int index){
  if (!root)
    return;

  PostOrderRecursive(root->left,ans,index);
  PostOrderRecursive(root->right,ans,index);
  root->data = ans[index];
  index++;
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Heapify(vector<int>& nums,int n,int i){
  int  largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if (left<n && nums[left]>nums[largest])
  {
    largest = left;
  }

  if (right<n && nums[right]>nums[largest])
  {
    largest = right;
  }
  

  if (largest!=i)
  {
    swap(nums[largest],nums[i]);
    Heapify(nums,n,largest);
  }
}

void BuildHeap(vector<int>&  nums){
  int n = nums.size();
  for (int i = (n/2)-1; i >= 0 ; i--)
    Heapify(nums,n,i);
}

// Merge Two Binary Max Heap
void MergetwoBinaryMaxGHeap(){
 /*

 Brute 
 Create a max priority Queue
  Insert all the element from both the heap and return that priority Queue
 */ 

 vector<int> arr1{5,4,3,2,1};
 vector<int> arr2{5,4,3,2,1};
 priority_queue<int> p;
  for(int x:arr1){
    p.push(x);
  }

  for(int x:arr2){
    p.push(x);
  }

  while (!p.empty())
  {
    cout<<p.top()<<" ";
    p.pop();
  }

  /*
  Better and Optimal
  Copy all the element in new array 
  and Hepify new Array
  */  
  
  int n = arr1.size();
  int m = arr2.size();
  vector<int> newArr;

  for(int x:arr1){
    newArr.push_back(x);
  }

  for(int x:arr2){
    newArr.push_back(x);
  }

  BuildHeap(newArr);
}

//Is Binary Tree Heap
//Property of Heap
//First it Should be complete tree
//Means There is No Node after null
//Parent Should be Greater than Child 

/*
Brute 
For Check of Complete Tree We use Level Order Traversal
and Check is node 
if null is found create a flag and put it equal to true 
if node is found chcek that isnull is true 
if yes return false else return true
*/

bool CompleteTreeCheck(TreeNode* root){
  queue<TreeNode*> q;
  q.push(root);
  bool flag = false;
  while (!q.empty())
  {
    TreeNode* temp = q.front();
    q.pop();
    if (temp==nullptr)
    {
      flag = true;
    }else{
      if (flag)
      {
        return false;
      }

      q.push(temp->left);
      q.push(temp->right);
    }
  }
  return true;
}


bool isHeapProperty(TreeNode* root){
  //A Nulltree is Complete tree
  if (root==nullptr)
  {
    return true;
  }

  //If Left or right any tof them is Greater Return false

  if (root->left && root->left->data>root->data)
  {
    return false;
  }

  if (root->right && root->right->data>root->data)
  {
    return false;
  }
  
  return isHeapProperty(root->left)&&isHeapProperty(root->right);
}

bool isHeap(TreeNode* tree){
  if (tree==nullptr)
  {
    return true;
  }
  return isHeapProperty(tree)&&CompleteTreeCheck(tree);
}


//We can Optimize the Space using DFS
/*

Better
So we know that if tree is complete
than totalnode == lastindex+1
or index<totalnode
So if at any point Index is greater than total node tree is Not Complete

*/

bool Count(TreeNode* root){
  
  if (root==nullptr)
  {
    return 0;
  }

  return 1+Count(root->left)+Count(root->right);
}


bool DFSTraversal(TreeNode* root,int n,int index){
  if (root==nullptr)
  {
    return true;
  }
  if (index>=n)
  {
    return false;
  }
  return DFSTraversal(root->left,n,2*index+1) && DFSTraversal(root->left,n,2*index+2);
}


//BST To Max Heap
/*

What we know is Max heap has largest element on the root
So we think that we can serach for greatest Element and store it onto the root
But the Problem is how we handle the connection ?

So maybe that approach fail
So we Know How to create Heap so waht we do is
we perform any traversal and store bst node data in array and heapify the array

*/

void Traversal(TreeNode* root,vector<int>& nums){
  if (root==nullptr)
  {
    return;
  }
  Traversal(root->left);
  nums.push_back(root->data);
  Traversal(root->right);
}

void BSTTOMAXHEAP(TreeNode* root){
  vector<int> nums;
  Traversal(root,nums);
  BuildHeap(nums);
}


/*

Better
What we know is we we perform inorder traversal we some tree
we get 1 2 3 4 5 6 7
Now if we make a max heap tree we know that parent is greater than left and right child
What we also know is root is greatest
so if we start from 1 then the tree will be wrong 
and if we start from end we know that 7 is root and then there left child is 6 and right is 5 or vica versa
But the problem is we going one side while making the tree so root is 7 and left child is 6 and thana there left child is 5 
So this is also wrong thought so what i can do is 
make the tree from leaf  so first left child will made than right child will made and then parent 
so parent visited last  so this is preorder traversal logic

Interview me ye 3 lines zarur bolna
BST ka Inorder hamesha sorted array deta hai.
Max Heap me parent children se bada hona chahiye.
Isliye sorted values ko Postorder me fill karte hain, taaki parent ko sabse baad me badi value mile.

*/

//Inorder Insertion is same as brute but rather than heapify we insert data in tree 
//Using postorder traversal
void PostInsertion(TreeNode* root,int& index,vector<int>& nums){
  if (root==nullptr)
  {
    return;
  }
  PostInsertion(root->left,index,nums);
  PostInsertion(root->right,index,nums);
  root->data = nums[index++];
}


int main(int argc, char const *argv[])
{

  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  for(int x:RightView(root)){
    cout<<x<<" ";
  }

  return 0;
}
