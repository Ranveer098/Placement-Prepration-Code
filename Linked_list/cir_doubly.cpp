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

node *ins_head(node *head, int x)
{
  node *tem = new node(x);
  if (head == NULL)
  {
    tem->next = tem;
    tem->prev = tem;
    return tem;
  }

  tem->prev = head->prev;
  tem->next = head;
  head->prev->next = tem;
  head->prev = tem;
  return tem;
}

node *insert_end(node*head,int x){
  node *tem = new node(x);
  if (head == NULL)
  {
    tem->next = tem;
    tem->prev = tem;
    return tem;
  }

  tem->prev = head->prev;
  tem->next = head;
  head->prev->next = tem;
  head->prev = tem;
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
  head = ins_head(head, 10);
  head = ins_head(head, 70);
  head = ins_head(head, 20);
  head = ins_head(head, 220);
  print(head);
  cout<<endl;
  insert_end(head,55);
  print(head);
}
