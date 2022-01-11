/*To Implement Double Ended Queue using Circular Double Linked List*/
#include<iostream>
using namespace std;
struct node
{
	public:
	int data;
	node *prev;
	node *next;
};
class DeQueue_CDLL
{
	node *head;
	int noe;
	public:
	DeQueue_CDLL() {head=NULL;noe=0;}
	void enqueueFront(int x);
	void enqueueRear(int x);
	int dequeueFront();
	int dequeueRear();
	void display();
	int sizeofQ();
	int FirstEle();
	int LastEle();
};
void DeQueue_CDLL::enqueueFront(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->prev=temp->next=NULL;
	noe++;
	if(head==NULL)
	{
		head=temp;
		temp->prev=temp->next=temp;
	}
	else
	{
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;
		head=temp;
	}
}
void DeQueue_CDLL::enqueueRear(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->prev=temp->next=NULL;
	noe++;
	if(head==NULL)
	{
		head=temp;
		temp->prev=temp->next=temp;
	}
	else
	{
		temp->prev=head->prev;
		temp->next=head;
		head->prev->next=temp;
		head->prev=temp;
	}
}
int DeQueue_CDLL::dequeueFront()
{
	node *temp;
	int x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";return 0;
	}
	else if(head->next==head) //when there is single element in list
	{
		temp=head;
		x=temp->data;
		head=NULL;
		delete temp;
		noe--;
		return x;
	}
	else
	{
		temp=head;
		x=temp->data;
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next;
		delete temp;
		noe--;
		return x;
	}
}
int DeQueue_CDLL::dequeueRear()
{
	node *temp;
	int x;
	if(head==NULL)    //When there are no elements in list 
	{
		cout<<endl<<"LIST IS EMPTY";
		return 0;
	}
	else if(head->next==head) //when there is single element in list
	{
		temp=head;
		x=temp->data;
		head=NULL;
		delete temp;
		noe--;
		return x;
	}
	else
	{
		temp=head->prev;
		x=temp->data;
		temp->prev->next=head;
		head->prev=temp->prev;
		delete temp;
		noe--;
		return x;
	}
}
void DeQueue_CDLL::display()
{
	node *p;
	p=head;
	while(p->next!=head)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
	cout<<p->data<<"\t";
}
int DeQueue_CDLL::sizeofQ()
{
	return noe;
}
int DeQueue_CDLL::FirstEle()
{
	return head->data;
}
int DeQueue_CDLL::LastEle()
{
	return head->prev->data;
}
int main()
{
	int ch,x,p;
	DeQueue_CDLL ob;
	while(1)
	{
		cout<<endl<<"1.Enqueue Front"<<endl<<"2.Enqueue Rear"<<endl<<"3.Deque Front"<<endl<<"4.Deque Rear"<<endl<<"5.Size of DQ"<<endl<<"6.Front Element";
		cout<<endl<<"7.Last Element"<<endl<<"8.Display"<<endl<<"9.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.enqueueFront(x);
					break;
			case 2:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.enqueueRear(x);
					break;
			case 3:	cout<<endl<<"Removed element is:"<<ob.dequeueFront();
					break;
			case 4:cout<<endl<<"Removed element is:"<<ob.dequeueRear();
					break;
			case 5:cout<<endl<<"size of queue is:"<<ob.sizeofQ();
					break;
			case 6:cout<<endl<<"First Element of queue is:"<<ob.FirstEle();
					break;
			case 7:cout<<endl<<"Last Element of queue is:"<<ob.LastEle();
					break;
			case 8:ob.display();
					break;
			case 9:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}
