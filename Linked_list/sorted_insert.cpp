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

node *insert_sorted(node *head, int x)
{
    node *temp = new node(x);
  if(head==NULL){ 
    return temp;
  }

  if (x < head->data)
  {
    head = insert_begin(head, x);
    return head;
  }
 
  node *curr = head;
  while (curr->next!=NULL && curr->next->data < temp->data)
  {
    curr = curr->next;
  }
  temp->next = curr->next;
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
  head = insert_begin(head, 60);
  head = insert_begin(head, 50);
  head = insert_begin(head, 40);
  print(head);
  cout << endl;
  head=insert_sorted(head, 30);
  print(head);
}