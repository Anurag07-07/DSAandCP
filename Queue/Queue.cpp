#include<bits/stdc++.h>
using namespace std;

class ListNode{
  public:
  int value;
  ListNode* next;
  ListNode(int value){
    this->value = value;
    next = nullptr;
  }
};

class Queue{
  int* arr;
  int front,rear;
  int size;
  public:
  Queue(int n){
    arr = new int[n];
    front = -1;
    rear = -1;
    size = n;
  }
  void pushCircular(int x){
    if (isEmpty())
    {
      rear = 0;
      front = 0;
      arr[rear] = x;
    }else if (isFull())
    {
      cout<<"Queue Overflow\n"<<endl;
    }else{
      rear = (rear+1)%size;
      arr[rear] = x;
    }
  }

  void push(int x){
    if (isEmpty())
    {
      rear = 0;
      front = 0;
      arr[rear] = x;
    }else if (isFull())
    {
      cout<<"Queue Overflow\n"<<endl;
    }else{
      rear = (rear+1);
      arr[rear] = x;
    }
  }

  void pop(){
    if (isEmpty())
    {
      cout<<"Queue Underflow\n"<<endl;
    }else{
      if (front==rear)
      {
        front = rear = -1;
      }else{
        front = (front+1);
      }
    }
  }
  
  void popCircular(){
    if (isEmpty())
    {
      cout<<"Queue Underflow\n"<<endl;
    }else{
      if (front==rear)
      {
        front = rear = -1;
      }else{
        front = (front+1)%size;
      }
    }
  }

  int start(){
    if (isEmpty())
    {
      cout<<"Queue is Empty\n";
      return -1;
    }else{
      return arr[front];
    }
  }

  bool isEmpty(){
    return front == -1;
  }

  bool isFull(){
    return rear == size-1;
  }

  bool isFullCircular(){
    return (rear+1)%size == front;
  }
};

class LLQueue{
  ListNode* front;
  ListNode* rear;
  public:
  LLQueue(){
    front = nullptr;
    rear = nullptr;
  }
  void push(int x){
    if (isEmpty())
    {
      front = new ListNode(x);
      rear = front;
      return;
    }else{
      rear->next = new ListNode(x);
      rear = rear->next;
    }
  }

  void pop(){
    if (isEmpty())
    {
      cout<<"Queue Underflow\n";
      return;
    }else{
      ListNode* temp = front;
      front = front->next;
      delete temp;
    }
  }

  bool isEmpty(){
    return front==nullptr;
  }

  int start(){
    if (isEmpty())
    {
      cout<<"Queue is Empty\n";
    }else{
      return front->value;
    }
  }
};

int main(int argc, char const *argv[])
{
  Queue q(10);
  q.push(45);
  q.push(45);
  q.push(5);
  q.pop();
  while (!q.isEmpty())
  {
    cout<<q.start()<<" ";
    q.pop();
  }
  return 0;
}