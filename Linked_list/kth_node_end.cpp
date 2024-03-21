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

void kth_end(node*head,int k){
  int len=0;
for(node *curr=head;curr!=NULL;curr=curr->next){
  len++;
}
if(len<k)return;
node *curr=head;
for ( int i = 1; i <len-k+1; i++)
{
  curr=curr->next;
}
cout<<(curr->data);


}
void kth__end(node *head,int k){
  if(head==NULL){
    return;
  }
  node *first=head;
  for (int i = 0; i <k; i++)
  {
    first=first->next;
  }
  node *sec=head;
  while (first!=NULL)
  {
    sec=sec->next;
    first=first->next;
  }
  cout<<(sec->data);
  
  
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
  cout<<endl;
  kth__end(head,3);
}
