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

void print_middle(node *head){
  if(head==NULL){
    return ;
  }
  node *slow=head, *fast=head;
  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<(slow->data);
  
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
  head = insert_begin(head, 15);
  head = insert_begin(head, 25);
  print(head);
  cout<<endl;
  print_middle(head);
}
