#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
  node *pre;
  node(int x){
    data=x;
    next=pre=NULL;
  }

};

node *insert_begin(node *head,int x){
  node *temp=new node(x);
  temp->next=head;
  if(head!=NULL){
    head->pre=temp;
  }
  return temp;

}

void print(node* head){
  node *curr=head;
  while (curr!=NULL)
  {
    cout<<(curr->data)<<"->";
    curr=curr->next;
    
  }
  
}

int main(){
  node *head=NULL;
  head=insert_begin(head,45);
  head=insert_begin(head,45);
  head=insert_begin(head,45);
  print(head);

}

