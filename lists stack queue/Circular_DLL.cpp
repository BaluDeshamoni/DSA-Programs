/*To implement circular linked list program which uses last as sentinal pointer*/
#include<iostream>
using namespace std;
struct node
{
	public:
	int data;
	node *prev
	node *next;
};

class CDLL
{
	node *last;
	public:
	CDLL() {last=NULL;}  //constructor to initialize
	void insertAtBegin(int x);
	void insertAtEnd(int x);
	void insertAtMiddle(int pos,int x);
	int removeAtBegin();
	int removeAtEnd();
	int removeAtMiddle(int pos);
	void display();
};
void CLL::insertAtBegin(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->prev=temp->next=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=last->prev=last;
	}
	else
	{
		
	}
}

void CLL::insertAtEnd(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=temp->prev=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=last->prev=last;
	}
	else
	{
		temp->prev=last;
		temp->next=last->next;
		last->next=temp;
		temp->next->prev=temp;
		last=temp;
	}
}
