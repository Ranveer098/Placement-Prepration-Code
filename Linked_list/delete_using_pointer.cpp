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

void deleteNode(node *ptr){
	node *temp=ptr->next;
	ptr->data=temp->data;
	ptr->next=temp->next;
	delete temp;



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
	node *head=new node(10);
	head->next=new node(20);
	node *ptr=new node(30);
	head->next->next=ptr;
	head->next->next->next=new node(40);
	head->next->next->next->next=new node(25);
	print(head);
	deleteNode(ptr);

	cout<<endl;
	print(head);
	return 0;
} 
