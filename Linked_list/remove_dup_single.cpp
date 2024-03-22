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

void deplicte__(node *head){
  node *curr=head;
  while (curr!=NULL && curr->next!=NULL){
    if (curr->data==curr->next->data)
    {
      node *temp=curr->next;
      curr->next=curr->next->next;
      delete temp;
    }
    else
    {
      curr=curr->next;
    }
    
    

  }
  
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
  head = insert_begin(head, 45);
  head = insert_begin(head, 15);
  head = insert_begin(head, 15);
  head = insert_begin(head, 10);
  print(head);
  cout <<endl;
  deplicte__(head);
  print(head);
  return 0;
}
