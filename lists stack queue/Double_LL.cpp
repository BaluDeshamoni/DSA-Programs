/*To implement Double Liked List head as sentinal pointer*/
#include<iostream>
using namespace std;
struct node
{
	public:
	int data;
	node *prev;
	node *next;
};

class DLL
{
	node *head;
	public:
	DLL() {head=NULL;}//constructor to initialize
	void insertAtBegin(int x);
	void insertAtEnd(int x);
	void insertAtMiddle(int pos,int x);
	int removeAtBegin();
	int removeAtEnd();
	int removeAtMiddle(int pos);
	void display();
	void reverseList();
};
void DLL::insertAtBegin(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->prev=temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void DLL::insertAtEnd(int x)
{
	node *temp=new node;
	node *p;
	temp->data=x;
	temp->prev=temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
		temp->prev=p;
	}
}
void DLL::insertAtMiddle(int pos,int x)
{
	node *temp=new node;
	temp->data=x;
	temp->prev=temp->next=NULL;
	node *p;
	int i=0;
	for(i=1,p=head;i<pos-1 && p!=NULL;i++)
			p=p->next;
	if(i==pos-1)
	{
		temp->next=p->next;
		temp->prev=p;
		p->next=temp;
		p->next->prev=temp;
	}
	else cout<<endl<<"WRONG POSITION NUMBER"<<endl;
}
int DLL::removeAtBegin()
{
	node *temp;
	int x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";return 0;
	}
	else if(head->next==NULL) //when there is single element in list
	{
		temp=head;
		head=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
	else
	{
		temp=head;
		head=temp->next;
		head->prev=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
}
int DLL::removeAtEnd()
{
	node *temp;
	int x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";
		return 0;
	}
	else if(head->next==NULL) //when there is single element in list
	{
		temp=head;
		head=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->prev->next=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
}
int DLL::removeAtMiddle(int pos)
{
	node *temp;
	int i,x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";
		return 0;
	}
	else
	{
		temp=head;
		for(i=1,temp=head;i<pos && temp!=NULL;i++)
			temp=temp->next;
		if(i==pos)	
		{
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			x=temp->data;
			delete temp;
			return x;
		}
		else cout<<endl<<"WRONG POSITION NUMBER"<<endl;
	}
}
void DLL::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}
int main()
{
	int ch,x,p;
	DLL ob;
	while(1)
	{
		cout<<endl<<"1.Insert at begin"<<endl<<"2.Insert at end"<<endl<<"3.Insert at middle";
		cout<<endl<<"4.Remove at begin"<<endl<<"5.Remove at end"<<endl<<"6.Remove at middle";
		cout<<endl<<"7.Display"<<endl<<"8.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.insertAtBegin(x);
					break;
			case 2:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.insertAtEnd(x);
					break;
			case 3:cout<<endl<<"Enter a position and an element to insert:";
					cin>>p>>x;
					ob.insertAtMiddle(p,x);
					break;
			case 4:	cout<<endl<<"Removed element is:"<<ob.removeAtBegin();
					break;
			case 5:cout<<endl<<"Removed element is:"<<ob.removeAtEnd();
					break;
			case 6:cout<<endl<<"Enter position value";
					cin>>p;		
					cout<<endl<<"Removed element is:"<<ob.removeAtMiddle(p);
					break;
			case 7:ob.display();
					break;
			case 8:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}
