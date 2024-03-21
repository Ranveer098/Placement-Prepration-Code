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

node *insert_pos(node *head, int pos, int x)
{
  node *temp = new node(x);
  if (pos == 1)
  {
    temp->next = head;
  }
  node *curr = head;

  for (int i = 1; i <= pos - 2 && curr != NULL; i++)
  {
    curr = curr->next;
  }
  if (curr == NULL)
  {
    return head;
  }
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

node *delete_begin(node* head){
  if(head==NULL) 
  {return NULL;}
  else{
   node  *temp=head->next;
   delete head;
   return temp;
  }
}

node *delete_end(node *head){
  if(head==NULL) return NULL;
  if(head->next==NULL){
    delete head;
    return NULL;
  }
  node *curr=head;

  while(curr->next->next!=NULL){
    curr=curr->next;
  }
  delete(curr->next);
  curr->next=NULL;
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
  head = inser_end(head, 22);
  print(head);
  cout << endl;
  insert_pos(head, 10, 500);
  head=delete_begin(head); 
  delete_end(head);
  print(head);
}
