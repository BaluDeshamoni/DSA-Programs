#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Stack
{
	int top,N;
	T *S;
	public:
	Stack()
	{
	    N=5;
		S=new T[N];
		top=-1;
	}
	bool isEmpty();
	bool isFull();
	void push(T x);
	T pop();
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
class Queue
{
	int *Q,front,rear,N;
	public:
	Queue()
	{
	    N=5;
		Q=new int[N];
		front=0;
		rear=-1;
	}
	bool isEmpty();
	bool isFull();
	void enqueue(int x);
	int dequeue();
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
void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}

void bfs(int s,vector<int>adj[],bool visit[]){
  Queue q;
  q.enqueue(s);
  visit[s]=true;
  while(!q.isEmpty()){
    int u=q.dequeue();
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.enqueue(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
void dfs(int s,vector<int>adj[],bool visit[]){
  Stack<int> st;
  st.push(s);
  visit[s]=true;
  while(!st.isEmpty()){
    int u=st.pop();
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        st.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
int main()
{
  vector<int>adj[5];
  bool visit[5];
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  edge(adj,0,2);
  edge(adj,0,1);
  edge(adj,1,3);
  edge(adj,2,0);
  edge(adj,2,3);
  edge(adj,2,4);
  cout<<"BFS traversal is"<<"  ";
  bfs(0,adj,visit);
  cout<<endl;
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";
  dfs(0,adj,visit);
}
