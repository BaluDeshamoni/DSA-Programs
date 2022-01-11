//To implement simple Queue using Array
#include<iostream>
using namespace std;
class Queue
{
	int *Q,front,rear,N;
	public:
	Queue()
	{
		cout<<"enter maximum number of elements in queue";
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
bool Queue::isEmpty()
{
	if(front>rear)
		return true;
	return false;		
}
bool Queue::isFull()
{
	if(rear==N-1)
		return true;
	return false;
}
void Queue::enqueue(int x)
{
	if(!isFull())
	{
		Q[++rear]=x;
	}
	else
		cout<<"\n Queue is FULL";
}
int Queue::dequeue()
{
	if(!isEmpty())
	{
		int x=Q[front];
		front++;
		return x;		
	}
	else
		cout<<"\n Queue is EMPTY";
}
int Queue::FirstEle()
{
	return Q[front];
}
int Queue::LastEle()
{
	return Q[rear];
}
int Queue::sizeofQ()
{
	return rear-front+1;
}
void Queue::display()
{
	for(int i=front;i<=rear;i++)
		cout<<"\t"<<Q[i];
	
}
int main()
{
	int ch,x;
	Queue ob;
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







