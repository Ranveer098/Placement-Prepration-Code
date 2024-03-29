#include <bits/stdc++.h>
using namespace std;

struct mystack
{
  int cap;
  int *arr;
  int top;
  mystack(int c)
  {
    cap = c;
    arr = new int[cap];
    top = -1;
  }

  void push(int x)
  {
    if (top == cap - 1)
    {
      cout << "stack is full";
      return;
    }
    top++;
    arr[top] = x;
  }
  int pop()
  {

    if (top == -1)
    {
      cout << "stack is empty";
      return INT_MIN;
    }
    int res = arr[top];
    top--;
    return res;
  }

  int peek()
  {
    if (top == -1)
    {
      cout << "stack is empty";
      return INT_MIN;
    }
    return arr[top];
  }
  int size(){
        return (top+1);
    }

  bool isempty()
  {
    return top == -1;
  }
};

int main()
{
  mystack s(4);
  s.push(5);
  s.push(5);
  s.push(5);
  s.push(5);
  s.push(5);
  cout<<s.pop();
  cout<<s.size();
  cout<<s.peek();

  
}
