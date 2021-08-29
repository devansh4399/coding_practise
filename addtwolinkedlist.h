// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       Node* current1=Reverse(first);
Node* current2=Reverse(second);
Node* head=NULL;
Node* newnd,*tempnd;

int sum,carry=0;

while(current1||current2)
{ if(current1==NULL)
sum=current2->data+carry;
else if(current2==NULL)
sum=current1->data+carry;
else
{
sum=current1->data+current2->data+carry;
}
carry=(sum>=10)?1:0;
sum=sum%10;
newnd=new Node(sum);
if(head==NULL)
{
head=tempnd=newnd;

}
else
{
tempnd->next=newnd;
tempnd=newnd;
}
if(current1)
current1=current1->next;
if(current2)
current2=current2->next;
}
if(carry)
tempnd->next=new Node(carry);
return Reverse(head);
}
    Node* Reverse(Node* head)
    {
        Node* current=head;
        Node *prev=NULL;
        Node *next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends