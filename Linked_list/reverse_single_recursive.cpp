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

node *reverse__(node *head)
{
  if (head == NULL || head->next ==NULL)
    return head;
    
  node *rest_head = reverse__(head->next);
  node *rest_tail = head->next;
  rest_tail->next = head;
  head->next = NULL;
  return rest_head;
}

void print(node *head)
{
  node *curr = head;
  while (curr != NULL)
  {
    cout << (curr->data) << "->";
    curr = curr->next;
  }
}

int main()
{
  node *head = NULL;
  head = insert_begin(head, 45);
  head = insert_begin(head, 5);
  head = insert_begin(head, 25);
  print(head);
  cout <<endl;
  head=reverse__(head);
  print(head);
  return 0;
}
