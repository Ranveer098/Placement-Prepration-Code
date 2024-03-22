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

node *insert_begin(node *head, int x)
{
  node *temp = new node(x);
  temp->next = head;
  return temp;
}
bool isloop(node *head)
{
  node *temp = new node(0);
  node *curr = head;
  while (curr != NULL)
  {
    if (curr->next == NULL)
      return false;
    if (curr->next == temp)
      return true;
    node *curr_next = curr->next;
    curr->next = temp;
    curr = curr_next;
  }
  return false;
}

bool isloop_(node *head)
{
  unordered_set<node *> s;
  for (node *curr = head; curr != NULL; curr = curr->next)
  {
    if (s.find(curr) != s.end())
    {
      return true;
    }
    s.insert(curr);
  }

  return false;
}

 
bool floyd(node *head){
  node *fast=head;
  node *slow=head;
  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      return true;
    }
  }
  return false;
  
}
int main()
{
  node *head = new node(15);
  head->next = new node(10);
  head->next->next = new node(12);
  head->next->next->next = new node(20);
  head->next->next->next->next = head->next;
  if (floyd(head))
  {
    cout << "loop found";
  }
  else
  {
    cout << "loop not  found";
  }
}
