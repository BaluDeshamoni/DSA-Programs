//To implement Circular Queue using Array. 
//If there is single element while removing then front and rear set to initial values
#include<iostream>
using namespace std;
class CQueue
{
	int *Q,front,rear,N;
	public:
	CQueue()
	{
		cout<<"enter maximum number of elements in CQueue";
		cin>>N;
		Q=new int[N];
		front=0;
		rear=-1;
	} 	
	bool isEmpty();
	bool isFull();
	void enqueue(int x);
	int dequeue();
	int sizeofQ();
	int FirstEle();
	int LastEle();
	void display();
};
bool CQueue::isEmpty()//To check whether Queue is empty or not
{
	if(rear==-1)
		return true;
	return false;		
}
bool CQueue::isFull()//To check whether Queue is full or not
{
	if((front==0&&rear==N-1) || (front!=0 and front==rear+1))
		return true;
	return false;
}
void CQueue::enqueue(int x)//inserts an element at rear side
{
	if(!isFull())
	{
		rear=(rear+1)%N;//if rear is pointing to N-1 then set to zero
		Q[rear]=x;
	}
	else
		cout<<"\n Queue is FULL";
}
int CQueue::dequeue()//removes an element from rear side
{
	if(!isEmpty())
	{
		
		int x=Q[front];
		if(rear==front)//checks for single element case
		{
			front =0;rear=-1;
		}    
		else front=(front+1)%N;//if front points to N-1 then set to zero
		return x;		
	}
	else
		cout<<"\n Queue is EMPTY";
}
int CQueue::FirstEle() //return the first element of the Queue
{
	return Q[front];
}
int CQueue::LastEle()//returns the last element of the Queue
{
	return Q[rear];
}
int CQueue::sizeofQ()//returns the size of the queue
{
	if(rear<front)
		return N-front+rear+1;
	else return rear-front+1;
}
void CQueue::display()
{
	int i;
	for(i=front;i!=rear;i=(i+1)%N)
		cout<<"\t"<<Q[i];
	cout<<"\t"<<Q[i];
	
}
int main()
{
	int ch,x;
	CQueue ob;
	while(1)
	{
		cout<<endl<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.SizeofQ";
		cout<<endl<<"4.First element"<<endl<<"5.Last Element"<<endl<<"6.Display"<<endl<<"7.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to enqueue:";
					cin>>x;
					ob.enqueue(x);
					break;
			case 2:	cout<<endl<<"dequeued element is:"<<ob.dequeue();
					break;
			case 3:cout<<endl<<"Size of Queue is:"<<ob.sizeofQ();
					break;
			case 4:cout<<endl<<"Front Elements is:"<<ob.FirstEle();
					break;
			case 5:cout<<endl<<"Last Elements is:"<<ob.LastEle();
					break;
			case 6: ob.display();
					break;
			case 7:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}







