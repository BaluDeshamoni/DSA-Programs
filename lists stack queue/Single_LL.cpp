/*To implement single linked list program
It also facilitates reverse function to reverse all the elements
*/
#include<iostream>
using namespace std;

struct node
{
	public:
	int data;
	node *next;
};

class SLL
{
	node *head;
	public:
	SLL() {head=NULL;} //constructor to initialize
	void insertAtBegin(int x);
	void insertAtEnd(int x);
	void insertAtMiddle(int pos,int x);
	int removeAtBegin();
	int removeAtEnd();
	int removeAtMiddle(int pos);
	void display();
	void reverseList();
};
void SLL::insertAtBegin(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
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
void SLL::insertAtEnd(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	node *p;
	if(head==NULL) // If the list is empty
	{
		head=temp;
	}
	else    //if the list is not empty then traverse till the end of the list
	{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
void SLL::insertAtMiddle(int pos,int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	node *p;
	int i=0;
	for(i=1,p=head;i<pos-1 && p!=NULL;i++)
			p=p->next;
	if(i==pos-1)
	{
		temp->next=p->next;
		p->next=temp;
	}
	else cout<<endl<<"WRONG POSITION NUMBER"<<endl;
}
int SLL::removeAtBegin()
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
		x=temp->data;
		delete temp;
		return x;
	}
}
int SLL::removeAtEnd()
{
	node *temp,*p;
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
		p=head;
		while(p->next->next!=NULL)
			p=p->next;
		temp=p->next;
		p->next=NULL;
		x=temp->data;
		delete temp;
		return x;
	}
}
int SLL::removeAtMiddle(int pos)
{
	node *temp,*p;
	int i,x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";
		return 0;
	}
	else
	{
		p=head;
		for(i=1,p=head;i<pos-1 && p!=NULL;i++)
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
void SLL::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}
void SLL::reverseList()
{
	SLL newone;
	while(head!=NULL)
	{
		int x=removeAtBegin();
		newone.insertAtBegin(x);
	}
	head=newone.head;
}
int main()
{
	int ch,x,p;
	SLL ob;
	while(1)
	{
		cout<<endl<<"1.Insert at begin"<<endl<<"2.Insert at end"<<endl<<"3.Insert at middle";
		cout<<endl<<"4.Remove at begin"<<endl<<"5.Remove at end"<<endl<<"6.Remove at middle";
		cout<<endl<<"7.Reverse the List"<<endl<<"8.Display"<<endl<<"9.Exit"<<endl<<"Enter Your Choice:";
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
			case 7:ob.reverseList();
					break;
			case 8:ob.display();
					break;
			case 9:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}
