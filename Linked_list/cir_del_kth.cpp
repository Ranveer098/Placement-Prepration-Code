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

// naive solution

node *insert_(node *head, int x)
{
  node *temp = new node(x);
  if (head == NULL)
  {
    temp->next = temp;
  }
  else
  {
    node *curr = head;
    while (curr->next != head)
    {
      curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
  }
  return temp;
}

// efficent solution

node *begin_(node *head, int x)
{
  node *temp = new node(x);
  if (head == NULL)
  {
    temp->next = temp;
  }
  else
  {
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
  }
}
node *lastt(node *head, int x)
{
  node *temp = new node(x);
  if (head == NULL)
  {
    temp->next = temp;
  }
  else
  {
    node *curr = head; 
    while (curr->next->next != head)
    {
      curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    int t = temp->data;
    temp->data = curr->next->next->data;
    curr->next->next->data = t;
    return head;
  }
}
node *delte_head(node*head){
  if(head==NULL) return NULL;
  if (head->next==head){
    delete head;
    return NULL;
  }
  head->data=head->next->data;
  node *temp=head->next;
  head->next=head->next->next;
  delete temp;
  return head;
}

node *del_kth(node*head,int k){
  if(k==1){
    delte_head(head);
  }
  node *curr=head;
  for (int i = 0; i <k-2; i++)
  {
    curr=curr->next;
  }
  node *temp=curr->next;
  curr->next=curr->next->next;
  delete temp;
  return head;
  
}

void print(node *head)
{
  node *curr = head;
  do
  {
    cout << (curr->data) << "->";
    curr = curr->next;

  } while (curr != head);
}

int main()
{
  node *head = NULL;
  head = insert_(head, 4);
  head = insert_(head, 22);
  head = insert_(head, 40);
  head = insert_(head, 2);
  head = begin_(head, 2555);
  lastt(head,100);
  print(head);
  cout<<endl;
  head=del_kth(head,2);
  print(head);
}