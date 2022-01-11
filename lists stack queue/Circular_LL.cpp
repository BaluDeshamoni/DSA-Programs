/*To implement circular linked list program which uses last as sentinal pointer*/
#include<iostream>
using namespace std;
struct node
{
	public:
	int data;
	node *next;
};

class CLL
{
	node *last;
	public:
	CLL() {last=NULL;}  //constructor to initialize
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
	temp->next=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=last;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
	}
}
void CLL::insertAtEnd(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(last==NULL)
	{
		last=temp;
		last->next=last;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}
void CLL::insertAtMiddle(int pos,int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	node *p;
	int i=0;
	for(i=1,p=last->next;i<pos-1 && p->next!=last->next;i++)
	{
		p=p->next;
	}
	if(i==pos-1)
	{
		temp->next=p->next;
		p->next=temp;
	}
	else cout<<endl<<"WRONG POSITION NUMBER"<<endl;
}
int CLL::removeAtBegin()
{
	node *temp;
	int x;
	if(last==NULL)    //When there are no elements in list 
		cout<<endl<<"LIST IS EMPTY";
	else if(last->next==last) //when there is single element in list
	{
		temp=last;
		last=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
	else
	{
		temp=last->next;
		last->next=temp->next;
		x=temp->data;
		delete temp;
		return x;
	}
}
int CLL::removeAtEnd()
{
	node *temp,*p;
	int x;
	if(last==NULL)    //When there are no elements in list 
		cout<<endl<<"LIST IS EMPTY";
	else if(last->next==last) //when there is single element in list
	{
		temp=last;
		last=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
	else
	{
		p=last->next;
		while(p->next!=last)
			p=p->next;
		temp=last;
		p->next=temp->next;
		last=p;
		x=temp->data;
		delete temp;
		return x;
	}
}
int CLL::removeAtMiddle(int pos)
{
	node *temp,*p;
	int i,x;
	if(last==NULL)    //When there are no elements in list 
		cout<<endl<<"LIST IS EMPTY";
	else
	{
		p=last->next;
		for(i=1,p=last->next;i<pos-1 && p->next!=last;i++)
			p=p->next;
		if(i==pos-1)	
		{
			temp=p->next;
			p->next=temp->next;
			x=temp->data;
			delete temp;
			return x;
		}
		else cout<<endl<<"WRONG POSITION NUMBER"<<endl;
	}
}
void CLL::display()
{
	node *p;
	p=last->next;
	while(p!=last)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<p->data<<"\t";
}
int main()
{
	int ch,x,p;
	CLL ob;
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
