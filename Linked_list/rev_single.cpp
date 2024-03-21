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

//naive solutuin
node *reverse_(node* head){
  vector<int>arr;
  for(node*curr=head;curr!=NULL;curr=curr->next){
    arr.push_back(curr->data);

  }
  for(node*curr=head;curr!=NULL;curr=curr->next){
    curr->data=arr.back();
    arr.pop_back();

  }
  return head;

}


//efficient solution

node *reverse__(node *head){
  node*curr=head;
  node *prev=NULL;
  while (curr!=NULL)
  {
    node *Next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=Next;
  }
  return prev;
  
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
  head=reverse__(head);
  print(head);
}
