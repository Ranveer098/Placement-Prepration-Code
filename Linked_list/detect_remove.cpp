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



void detect(node *head){
  node *fast=head;
  node *slow=head;
  while (fast!=NULL && fast->next!=NULL)
  {
   slow=slow->next;
   fast=fast->next->next;
  if(slow==fast){
    break;
  }
  
  }
  if(slow!=fast){
    return;
  }
  slow=head;
  while(slow->next!=fast->next){
    slow=slow->next;
    fast=fast->next;

  }
  fast->next=NULL;
}

bool flo(node *head){
  node *fast=head;
  node *slow=head;
  while (fast!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      return true;
    }
  }
  return false;
  
}


 

int main()
{
  node *head = new node(15);
  head->next = new node(10);
  head->next->next = new node(12);
  head->next->next->next = new node(20);
  head->next->next->next->next = head->next;
  detect(head);
  if (flo(head))
  {
    cout << "loop found";
  }
  else
  {
    cout << "loop not  found";
  }
}
