#include<iostream>
using namespace std;
template<class T>
struct node
{
	public:
	T data;
	node *left,*right;
};
template<class T>
class binarytree
{
	public:
    node<T> *root,*temp;
    binarytree()
    {         root=NULL;temp=NULL;    }
	void search(node<T>*,T);
	void insert();
	void inorder(node<T>*);
	void preorder(node<T>*);
	void postorder(node<T>*);
	void display();
};
template<class T>
void binarytree<T>::search(node<T> *p, T x)
{
    	if(p!=NULL)
        {
        	if(p->data==x)
        	{
        		temp=p;
            	cout<<"\n Element "<<p->data<<" is found \n";
        	}
			search(p->left,x);
        	search(p->right,x);
        }
}
template<class T>
void binarytree<T>::insert()
{
    temp=NULL; // Search function will update this variable when element is found 
    if(root==NULL)
    {
        root=new node<T>;
        cout<<"\n enter value \n";
        cin>>root->data;
        root->left=NULL;
        root->right=NULL;
        cout<<"\n value inserted successfully \n ";
    }
    else
    {
        cout<<"\n Enter the parent value, where you wanted to insert the value \n";
        T x;
        cin>>x;
        node<T> *p;
        search(root,x); // this method updates temp variable, if ele is found 
        if(temp==NULL) 
          	cout<<"\n ELement Not found \n";
        else
        {
	    		p=temp;
            	if(p->left!=NULL && p->right!=NULL)
            		cout<<"\nInsertion Failed "<<p->data<<" have both childs,choose other parent\n";
            	else 
				{
	                cout<< "\n Enter 1 for left , 2 for right";
    	            int ch;
                    cin>>ch;
                    if(ch==1)
                    {
                        if(p->left!=NULL)
                        	cout<<"\n Left is not free \n";
                        else
                        {
                        	p->left=new node<T>;
                        	p=p->left;
                        	cout<<"\n enter value \n";
                        	cin>>p->data;
                        	p->left=NULL;
                        	p->right=NULL;
                        	cout<<"\n value inserted successfully \n ";
                        }
                    }
                    else if(ch==2)
                    {
                        if(p->right!=NULL)
                        cout<<"\n Right is not free \n";
                        else
                        {
                        	p->right=new node<T>;
                        	p=p->right;
                        	cout<<"\n enter value \n";
                        	cin>>p->data;
                        	p->left=NULL;
                        	p->right=NULL;
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
        inorder(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        postorder(root);

    }
 }
template<class T>
void binarytree<T>::inorder(node<T> *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<"   "<<p->data;
    inorder(p->right);

}
template<class T>
void binarytree<T>::preorder(node<T> *p)
{
    if(p==NULL)
        return;
    cout<<"  "<<p->data;
    preorder(p->left);
    preorder(p->right);

}
template<class T>
void binarytree<T>::postorder(node<T> *p)
{
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout<<"   "<<p->data;


}
int main()
{
    binarytree<char> ob;
    int x;
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
