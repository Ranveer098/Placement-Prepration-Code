#include <bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  Node *next;
  Node(char x)
  {
    data = x;
    next = NULL;
  }
};

Node *reverse_(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  Node *rest_head = reverse_(head->next);
  Node *rest_tail = head->next;
  rest_tail->next = head;
  head->next = NULL;
  return rest_head;
}

 bool ispalidrome__(Node *head){
  if(head==NULL) return true;
  Node *fast=head; Node*slow=head;
  while (fast->next!=NULL && fast->next->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
  }
  Node *rev=reverse_(slow->next);
  Node *curr=head;
  while (rev!=NULL)
  {
    if(rev->data!=curr->data) return false;
    rev=rev->next;
    curr=curr->next;
    
  }
  return true;
  
  
 }
// Naive solution
bool isPalindrome(Node *head)
{
  stack<char> st;
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    st.push(curr->data);
  }
  for (Node *curr = head; curr != NULL; curr = curr->next)
  {
    if (st.top() != curr->data)
    {
      return false;
    }
    st.pop();
  }
  return true;
}

// efficient solution

int main()
{
  Node *head = new Node('g');
  head->next = new Node('f');
  head->next->next = new Node('g');
  if (ispalidrome__(head))
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
