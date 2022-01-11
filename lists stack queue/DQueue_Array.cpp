/*This Program is to implement Double Ended Queue using array
  Note that the array is not circular, but if dequeue operation is done when single element exists
  then front and rear are initialized to 0 and -1 respectively
*/
#include<iostream>
using namespace std;
class DQueue
{
	int *Q,front,rear,N;
	public:
	DQueue()
	{
		cout<<"enter maximum number of elements in DQueue";
		cin>>N;
		Q=new int[N];
		front=0;
		rear=-1;
	} 	
	bool isEmpty();
	bool isFull();
	void enqueue_rear(int x);
	void enqueue_front(int x);
	int dequeue_front();
	int dequeue_rear();
	int sizeofQ();
	int FirstEle();
	int LastEle();
	void display();
};
bool DQueue::isEmpty() // to check whether queue is empty or not
{
	if(rear==-1 && front==0)
		return true;
	return false;		
}
bool DQueue::isFull()   // to check whether queue is full or not
{
	if(front==0&&rear==N-1)
		return true;
	return false;
}
void DQueue::enqueue_rear(int x)//inserts element using rear reference
{
	if(!isFull())
	{
		if(rear==N-1)//not possible if there are elements and rear is at end position 					
		{
			cout<<"\nENQUEUE not Possible";return;
		}
		Q[++rear]=x;
	}
	else
		cout<<"\n Queue is FULL";
}
void DQueue::enqueue_front(int x)// inserts element using front reference
{
	if(!isFull())
	{
		if(isEmpty()) rear=0; //if Queue is empty rear reinitialized to zero
		else if(front==0) //not possible to insert if there are elements and front pointing to zero
		{
			cout<<"\nENQUEUE not Possible";return;
		}
		Q[--front]=x;
	}
	else
		cout<<"\n Queue is FULL";
}
int DQueue::dequeue_front()//remove element at front side
{
	if(!isEmpty())
	{
		int x=Q[front];
		if(rear==front) //if there is single element front and rear set to initial values
		{
			front=0;rear=-1;
		}
		else front++;
		return x;	
	}
	else
		cout<<"\n Queue is EMPTY";
}
int DQueue::dequeue_rear()//remove element at rear side
{
	if(!isEmpty())
	{
		int x=Q[rear];
		if(rear==front)//if there is single element front and rear set to initial values
		{
			front=0;rear=-1;
		}
		else rear--;
		return x;
	}		
	else
		cout<<"\n Queue is EMPTY";
}
int DQueue::FirstEle()//returns the first element of Queue
{
	return Q[front];
}
int DQueue::LastEle()//returns the last element of Queue
{
	return Q[rear];
}
int DQueue::sizeofQ()//returns the size of the Queue
{
	return rear-front+1;
}
void DQueue::display()
{
	int i;
	for(i=front;i<=rear;i++)
		cout<<"\t"<<Q[i];
}
int main()
{
	int ch,x;
	DQueue ob;
	while(1)
	{
		cout<<endl<<"1.enqueue_rear"<<endl<<"2.enqueue_front"<<endl<<"3.dequeue_front"<<endl<<"4.dequeue_rear"<<endl;
		cout<<"5.SizeofQ"<<endl<<"6.First element"<<endl<<"7.Last Element"<<endl;
		cout<<"8.Display"<<endl<<"9.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to enqueue_rear:";
					cin>>x;
					ob.enqueue_rear(x);
					break;
			case 2:cout<<endl<<"Enter an element to enqueue_front:";
					cin>>x;
					ob.enqueue_front(x);
					break;
			case 3:	cout<<endl<<"dequeue_front element is:"<<ob.dequeue_front();
					break;
			case 4:	cout<<endl<<"dequeue_rear element is:"<<ob.dequeue_rear();
					break;
			case 5:cout<<endl<<"Size of Queue is:"<<ob.sizeofQ();
					break;
			case 6:cout<<endl<<"Front Elements is:"<<ob.FirstEle();
					break;
			case 7:cout<<endl<<"Last Elements is:"<<ob.LastEle();
					break;
			case 8: ob.display();
					break;
			case 9:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}






