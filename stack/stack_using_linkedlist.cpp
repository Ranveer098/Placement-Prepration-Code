#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};
struct MyStack
{
  node *head;
  int sz;
  MyStack()
  {
    head = NULL;
    sz = 0;
  }

  void push(int x)
  {
    node *temp = new node(x);
    temp->next = head;
    head = temp;
    sz++;
  }
  int pop()
  {
    if (head == NULL)
    {
      return INT_MAX;
    }

    int res = head->data;
    node *temp = head;
    head = head->next;
    delete temp;
    sz--;
    return res;
  }
  bool isEmpty()
  {
    return (head == NULL);
  }
  int size()
  {
    return sz;
  }
  int peek()
  {
    if (head == NULL)
    {
      return INT_MAX;
    }
  return head->data;
  }
};

int main()
{
  MyStack s;
  s.push(5);
  s.push(10);
  s.push(20);
  cout << s.pop() << endl;
  cout << s.size() << endl;
  cout << s.peek() << endl;
  cout << s.isEmpty() << endl;

  return 0;
}