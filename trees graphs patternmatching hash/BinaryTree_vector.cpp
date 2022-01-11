#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class binarytree
{
	public:
    T *V,C;
	int l,ms,temp;
    binarytree()
    {         
		cout<<"\nEnter Maximum No of levels:";
		cin>>l;
		ms=pow(2,l)-1;
		V=new T [ms];  //space created for maximum elements in l levels
		cout<<"\nenter global constant to intialize the vector";
		cin>>C;
		for(int i=0;i<ms;i++)
			V[i]=C; 
	}
	void search(int key, int i);//key is the element to search and i is the index of the root node
	void insert();
	void inorder(int i);  //i is index of the root node
	void preorder(int i);
	void postorder(int i);
	void display();
};
template<class T>
void binarytree<T>::search(int key,int i)
{
    	if(V[i]!=C)
        {
        	if(V[i]==key)
        	{
        		temp=i;
            	cout<<"\n Element "<<V[i]<<" is found \n";
				return;
        	}
        	if(2*i+1 < ms) search(key,2*i+1);
        	if(2*i+2 < ms) search(key,2*i+2);
        }
        
}
template<class T>
void binarytree<T>::insert()
{
    temp=-1; // Search function will update this variable when element is found 
    if(V[0]==C)
    {
        cout<<"\n enter value \n";
        cin>>V[0];
        cout<<"\n value inserted successfully \n ";
    }
    else
    {
        cout<<"\n Enter the parent value, where you wanted to insert the value \n";
        T x;
        int p;
        cin>>x;
        search(x,0); // this method updates temp variable, if ele is found 
        if(temp==-1) 
          	cout<<"\n Element Not found \n";
        else
        {
        		cout<<endl<<temp;
	    		p=temp;
            	if(V[2*p+1]!=C && V[2*p+2]!=C)
            		cout<<"\nInsertion Failed "<<V[p]<<" have both childs,choose other parent\n";
            	else 
				{
	                cout<< "\n Enter 1 for left , 2 for right";
    	            int ch;
                    cin>>ch;
                    if(ch==1)
                    {
                        if(V[2*p+1]!=C)
                        	cout<<"\n Left is not free \n";
                        else
                        {
                        	cout<<"\n enter value \n";
                        	cin>>V[2*p+1];
                        	cout<<"\n value inserted successfully \n ";
                        }
                    }
                    else if(ch==2)
                    {
                        if(V[2*p+2]!=C)
                        	cout<<"\n Right is not free \n";
                        else
                        {
                        	cout<<"\n enter value \n";
                        	cin>>V[2*p+2];
                        	cout<<"\n value inserted successfully \n ";
                        }
                    }
                    else
                    {	cout<<"\n Not a valid input enter 1 or 2\n";return;}
            	}
        }
    }

}


template<class T>
 void binarytree<T>::display()
 {
    cout<<"\n1.Inorder   2.Preorder   3.Postorder  \nEnter Your Choice:";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        inorder(0);
        break;
    case 2:
        preorder(0);
        break;
    case 3:
        postorder(0);

    }
 }
template<class T>
void binarytree<T>::inorder(int i)
{
    if(V[i]!=C)
	{
	    if(2*i+1 < ms) inorder(2*i+1);
    	cout<<"   "<<V[i];
    	if(2*i+2 < ms) inorder(2*i+2);
	}
}
template<class T>
void binarytree<T>::preorder(int i)
{
    if(V[i]==C)
        return;
    cout<<"  "<<V[i];
    if(2*i+1 < ms) preorder(2*i+1);
    if(2*i+2 < ms) preorder(2*i+2);
	

}
template<class T>
void binarytree<T>::postorder(int i)
{
    if(V[i]==C)
        return;
    if(2*i+1 < ms) postorder(2*i+1);
	if(2*i+1 < ms) postorder(2*i+2);
	cout<<"   "<<V[i];


}
int main()
{
    binarytree<char> ob;
    int ch;
    while(1)
    {
    	cout<<"\n1.INSERT  2.DISPLAY  3.EXIT \n Enter YOUR Choice";
    	cin>>ch;
    	switch(ch)
    	{
			case 1:
    			ob.insert();
    			break;
			case 2:
    			ob.display();
    			break;
			case 3:
    			return 0;
    	}
	}
}
