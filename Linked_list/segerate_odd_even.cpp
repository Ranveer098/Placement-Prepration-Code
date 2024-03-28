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
node *seg_(node *head)
{
  node *es= NULL, *ee= NULL,*os= NULL,*oe = NULL;
  for (node *curr = head; curr != NULL; curr = curr->next)
  {
    int x = curr->data;
    if (x % 2 == 0)
    {
      if (es == NULL)
      {
        es =curr;
        ee = es;
      }
      else
      {
        ee->next = curr;
        ee = ee->next;
      }
    }
    else
    {
      if (os == NULL)
      {
        os =curr;
        oe = os;
      }
      else
      {
        oe->next = curr;
        oe = oe->next;
      }
    }
  }
  if (es == NULL || os == NULL)
  {
    return head;
  }
  ee->next = os;
  oe->next = NULL;
  return es;
}

void print(node *head)
{
  node *curr = head;
  while (curr != NULL)
  {
    cout << (curr->data) << "->";
    curr = curr->next;
  }cout<<endl;
}

int main()
{
  node *head = NULL;
  head = insert_begin(head, 45);
  head = insert_begin(head, 44);
  head = insert_begin(head, 5);
  head = insert_begin(head, 5);
  head = insert_begin(head, 2);
  head = insert_begin(head, 25);
  print(head);
  head=seg_(head);
  print(head);
  return 0;
}
