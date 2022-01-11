#include<iostream>
using namespace std;

struct node
{
	public:
	int data;
	node *next;
};
template <class T>
class StackLL
{
	node *last;
	int noe;
	public:
	StackLL() {last=NULL;noe=0;}
	void push(T x);
	T pop();
	T topElement();
	int sizeofStack();
	void display();
};
template <class T>
int StackLL<T>::sizeofStack()
{
	return noe;	
}
template <class T>
T StackLL<T>::topElement()
{
	if(last!=NULL)
		return last->next->data;
}
template <class T>
void StackLL<T>::push(T x)
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
	noe++;
}
template <class T>
T StackLL<T>::pop()
{
	node *temp;
	T x;
	if(last==NULL)    //When there are no elements in list 
		cout<<endl<<"LIST IS EMPTY";
	else if(last->next==last) //when there is single element in list
	{
		temp=last;
		last=NULL;
		x=temp->data;
		delete temp; noe--;
		return x; 
	}
	else
	{
		temp=last->next;
		last->next=temp->next;
		x=temp->data;
		delete temp; noe--;
		return x;
	}
}
template <class T>
void StackLL<T>::display()
{
	node *p;
	p=last->next;
	while(p!=last)
	{
		cout<<"\t\t"<<p->data<<endl;
		p=p->next;
	}
	cout<<"\t\t"<<p->data<<endl;
}
int main()
{
	int ch,x;
	StackLL<int> ob;
	while(1)
	{
		cout<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Size";
		cout<<endl<<"4.Top element"<<endl<<"5.Display"<<endl<<"6.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to push:";
					cin>>x;
					ob.push(x);
					break;
			case 2:	cout<<endl<<"Popped element is:"<<ob.pop();
					break;
			case 3:cout<<endl<<"Size of stack is:"<<ob.sizeofStack();
					break;
			case 4:cout<<endl<<"Top Elements is:"<<ob.topElement();
					break;
			case 5:cout<<endl<<"The stack is:"<<endl;
					ob.display();
					break;
			case 6:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}
