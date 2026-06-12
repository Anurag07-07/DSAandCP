#include<bits/stdc++.h>
using namespace std;

class QueueUsingStack{
  stack<int> st1;
  stack<int> st2;
  public:
  bool empty(){
    return st1.empty() && st2.empty();
  }

  void push(int x){
    st1.push(x);
  }

  int pop(){
    if (empty())
    {
      return 0;
    }

    if (!st2.empty())
    {
      int element = st2.top();
      st2.pop();
      return element;
    }else{
      while (!st1.empty())
      {
        st2.push(st1.top());
        st1.pop();
      }
      int element = st2.top();
      st2.pop();
      return element;
    }
  }

  int peek(){
    if (empty())
    {
      return 0;
    }
    if (!st2.empty())
    {
      return st2.top();
    }else{
      while (!st1.empty())
      {
        st2.push(st1.top());
        st1.pop();
      }
      return st2.top();
    }
  }
};

class StackUsingQueue{
  queue<int> q1;
  queue<int> q2;
  public:
  bool empty(){
    return q1.empty() && q2.empty();
  }
  void push(int x){
    if (empty())
    {
      q1.push(x);
    }else if (q1.empty())
    {
      q2.push(x);
    }else{
      q1.push(x);
    }
  }
  int pop(){
    if (empty())
    {
      return 0;
    }else if(q1.empty()){
      //Element q2 me honge
      //Ek chorkar sare element le aao
      while (q2.size()>1)
      {
        q1.push(q2.front());
        q2.pop();
      }
      int element  = q2.front();
      q2.pop();
      return element;
    }else{
      while (q1.size()>1)
      {
        q2.push(q1.front());
        q1.pop();
      }
      int element  = q1.front();
      q1.pop();
      return element;
    }
  }

  int top(){
    if (empty())
    {
      return 0;
    }else{
      if (q1.empty())
      {
        return q2.back();
      }else{
        return q1.back();
      }
    }
  }
};

void QueueElementPrint(){
  queue<int> q;
  for (int i = 1; i < 11; i++)
    q.push(i);

    vector<int> temp;
  
  while (!q.empty())
  {
    cout<<q.front()<<" ";
    temp.push_back(q.front());
    q.pop();
  }
  cout<<endl;

  for(int x:temp){
    cout<<x<<" ";
  }
}

void QueueReversal(queue<int> q){
  stack<int> s;
  while (!q.empty())
  {
    s.push(q.front());
    q.pop();
  }

  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }
  
  while (!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }
  
}

void QueueElementPrintOptimal(){
  queue<int> q;
  for (int i = 1; i < 11; i++)
    q.push(i);

    vector<int> temp;

    int size = q.size();
    int value;
  while (!q.empty() && size)
  {
    cout<<q.front()<<" ";
    value = q.front();
    q.pop();
    size--;
    q.push(value);
  }
  cout<<endl;
  
  while (!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }
}
int TimeNeededToBuyTicket(vector<int> tickets,int K){
  // LC 2073
  queue<int> q;
  for (int i = 0; i < q.size(); i++)
    q.push(i);

  int time = 0;
  int val;
  while (tickets[K]!=0)
  {
    val = tickets[q.front()]--;
    q.pop();
    time++;
    if (val)
    {
      q.push(val);
    }
    
  }
    
  return time;
}
void ReverseK(queue<int> q,int K){
  stack<int> st;
  int left;
  int size = q.size();
  while (!q.empty() && K--)
  {
    st.push(q.front());
    q.pop();
  }

  left = size-q.size();

  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }
  
  int val;
  while (left--)
  {
    val = q.front();
    q.pop();
    q.push(val);
  }
  
  while (!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }

}
int main(int argc, char const *argv[])
{
  queue<int> q;
  for (int i = 1; i < 11; i++)
    q.push(i);

  // QueueReversal(q);  
  // QueueElementPrint();
  // QueueElementPrintOptimal();
  ReverseK(q,5);
  return 0;
}
