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

node *inser_end(node *head, int x)
{
  node *temp = new node(x);
  if (head == NULL)
  {
    return temp;
  }

  node *curr = head;
  while (curr->next != NULL)
  {

    curr = curr->next;
  }
  curr->next = temp;
  return head;
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
  head = insert_begin(head, 20);
  head = insert_begin(head, 10);
  head = insert_begin(head, 50);
  print(head);
  cout << endl;

  head = inser_end(head, 100);
  head=inser_end(head,22);
  print(head);
}
