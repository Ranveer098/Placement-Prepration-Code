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

int search_(node *head, int x)
{
  int pos = 1;
  node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == x)
    {
      return pos;
    }
    else
    {
      pos++;
      curr=curr->next;
    }
    
  }
  return -1;
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
  head = insert_begin(head, 55);
  head = insert_begin(head, 15);
  head = insert_begin(head, 25);
  head = insert_begin(head, 5);
  head = insert_begin(head, 45);
  head = insert_begin(head, 95);
  print(head);
  cout<<"Position of element in Linked List: "<<search_(head,25);
}