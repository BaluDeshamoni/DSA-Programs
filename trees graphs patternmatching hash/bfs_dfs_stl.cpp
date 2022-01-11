#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//add the edge in graph
//(0,3)-->adj[0].push_back(3)
void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
//function for bfs traversal
void bfs(int s,vector<int>adj[],bool visit[]){
  queue<int>q;//1. create a queue in STL
  q.push(s); // 2. push starting vertex and visit
  visit[s]=true;
  // 3. dequeue element
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
    //4.push and visit adjacent nodes which are not visited
   //loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]); //enqueue into queue
        visit[adj[u][i]]=true; //visit the connected vertex
      }
    }
  }
}
//function for dfs traversal
void dfs(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;//1. create a stack in STL
  stk.push(s);// 2. push starting node and visit
  visit[s]=true;
  //3. pop an element
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
//loop for traverse
    //4. push and visit adjacent nodes which are not visited
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);  //push into stack
        visit[adj[u][i]]=true; //visit those vertices
      }
    }
  }
}
//main function
/*
Vectors to represent adjacency List-->adj
0-->1,2  vector adj[0]
1-->3
2-->0,3,4
3-->
4-->
Visit array
0 1 2 3 4
F F F F F
*/
int main()
{
  vector<int>adj[5];//vector of array to store the graph
  bool visit[5];//array to check visit or not of a node
  //initially all node are unvisited
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  //input for edges
  edge(adj,0,2);
  edge(adj,0,1);
  edge(adj,1,3);
  edge(adj,2,0);
  edge(adj,2,3);
  edge(adj,2,4);
  cout<<"BFS traversal is"<<"  ";
  //call bfs funtion
  bfs(0,adj,visit);//1st vertex is a starting point
  cout<<endl;
  //again initialise all node unvisited for dfs
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";
  //call dfs function
  dfs(0,adj,visit);//1 is a starting point
}
