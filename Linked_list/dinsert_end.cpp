#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *next;
  node *prev;
  node(int x)
  {
    data = x;
    next = prev = NULL;
  }
};

node *insert_begin(node *head, int x)
{
  node *temp = new node(x);
  temp->next = head;
  if (head != NULL)
  {
    head->prev = temp;
  }
  return temp;
}
node *insert_end(node *head, int x)
{
  node *temp = new node(x);
  if (head == NULL)
    return temp;

  node *curr = head;
  while (curr->next!= NULL)
  {
    curr = curr->next;
  }
  curr->next = temp;
  temp->prev = curr;
  return head;
}

node*delete_head(node* head){
  if(head==NULL){
    return NULL;
  }
  node *temp=head->next;
  delete head;
  return temp;
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
  head=insert_end(head, 15);
  print(head);
}
