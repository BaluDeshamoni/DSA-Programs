/*To implement stack program using array along with matching paranthesis*/
#include<iostream>
#include<string>
using namespace std;
bool isOpenParen(char ch)
{
	if(ch=='{'||ch=='('||ch=='<'||ch=='[') return true;
	return false;
}
bool isClosedParen(char ch)
{
	if(ch=='}'||ch==')'||ch=='>'||ch==']') return true;
	return false;
}
bool isMatch(char x, char y)
{
	if((y=='{' && x=='}')||(y=='[' && x==']')||(y=='<' && x=='>')||(y=='(' && x==')'))
				return true;
	else return false;
}
template<class T>
class Stack
{
	int top,N;
	T *S;
	public:
	Stack()   //constructor to initialize
	{
		cout<<endl<<"Enter the maximum size of the stack";
		cin>>N;
		S=new T[N];
		top=-1;
	}
	~Stack() { delete S;}
	bool isEmpty();
	bool isFull();
	void push(T x);
	T pop();
	int sizeofStack();
	T topElement();
	void display();
	void matchParen(string str);
	void infixToPostfix(string str);
};
template<class T>
bool Stack<T>::isEmpty()
{
	if(top==-1) return true;
	return false;
}
template<class T>
bool Stack<T>::isFull()
{
	if(top==N-1) return true;
	return false;
}
template<class T>
void Stack<T>::push(T x)
{
	if(!isFull())
		S[++top]=x;	
	else
		cout<<endl<<"Stack is FULL";
}
template<class T>
T Stack<T>::pop()
{
	if(!isEmpty())
		return S[top--];
	else
		cout<<endl<<"Stack is empty";
}
template<class T>
T Stack<T>::topElement()
{
	if(!isEmpty())
		return S[top];
	else
		cout<<endl<<"Stack is empty";
}
template<class T>
int Stack<T>::sizeofStack()
{
	return top+1;
}
template<class T>
void Stack<T>::display()
{
	cout<<endl;
	for(int i=top;i>=0;i--)
		cout<<"\t"<<S[i]<<endl;
}
template <class T>
void Stack<T>::matchParen(string str)
{
	int N=str.length();
	S=new T[N];
	top=-1;
	char y;
	for(int i=0;i<N;i++)
	{
		if(isOpenParen(str[i]))
			push(str[i]);
		else 
		{
			if(isClosedParen(str[i]))
			{				
				if(!isEmpty())
					y=pop();
				else
				{
					cout<<endl<<"INCORRECT";
					return;
				}
				if(!isMatch(str[i],y))
				{
					cout<<endl<<"INCORRECT";
					return;
				}	
				else continue;
			}
		}
	}
	if(!isEmpty())
	{
		cout<<endl<<"INCORRECT";
		return;
	}
	else
		cout<<endl<<"CORRECT";
}
template <class T>
void Stack<T>::infixToPostfix(string str)
{
	
	
}
int main()
{
	int ch;
	char x;
	string str;
	Stack<char> ob;
	while(1)
	{
		cout<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Size";
		cout<<endl<<"4.Top element"<<endl<<"5.Display"<<endl<<"6.Matching Paranthesis"<<endl<<"7.Exit"<<endl<<"Enter Your Choice:";
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
			case 5:ob.display();
					break;
			case 6: cout<<"\nEnter a set of parantheis to validate:"<<endl;
					cin>>str;
					ob.matchParen(str);break;
			case 7:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}
