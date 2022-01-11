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
class BST
{
public:
    node<T> *root,*temp,*parent;
    BST()
    {
         root=NULL;temp=NULL;parent=NULL;
    }
void search(node<T>*,T);
void insert();
void remove();
void inorder(node<T>*);
void preorder(node<T>*);
void postorder(node<T>*);
void display();
};
template<class T>
void BST<T>::search(node<T> *p, T x)
{
    while(p!=NULL)
    {
        if(p->data==x)
        {
        temp=p;
        cout<<"\n Element is found \n";
        return;
        }
        else if(x<(p->data))
        {
            parent=p;
            p=p->left;
        }
        else
        {
            parent=p;
            p=p->right;
        }
    }
}
template<class T>
void BST<T>::insert()
{
    temp=NULL;parent=NULL;
    int key;
    cout<<"\n Enter value: ";
    cin>>key;
    node<T> *p = new node<T>;
    p->data=key;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        cout<<"\n Value inserted successfully \n ";
    }
    else
    {
        search(root,key);
        if(temp!=NULL)
        {
            cout<<"\n Duplicate Exists";return;
        }
        else
        {
            if(key < parent->data)
                parent->left=p;
            else
                parent->right=p;
        }
    }
}

template<class T>
void BST<T>::remove()
{
    int key;
    if(root==NULL)
    cout<<"\n TREE IS EMPTY \n ";
    else
    {
    temp=NULL;
    parent=NULL;
    cout<<"\n Enter the element to be Deleted \n ";
    cin>>key;
    search(root,key);
    if(temp==NULL)
    cout<<"\n ELEMENT NOT FOUND \n";
    else if(temp->left==NULL && temp->right==NULL)
    {
        if(parent==NULL)
        root=NULL;
        else if(parent->left==temp)
        parent->left=NULL;
        else
        parent->right=NULL;
        delete temp;
        cout<<"\n Deletion success \n ";
    }
    else if(temp->left!=NULL && temp->right==NULL)
    {
    if(parent==NULL)
    root=temp->left;
    else if(parent->left==temp)
    parent->left=temp->left;
    else if(parent->right==temp)
    parent->right=temp->left;
    delete temp;
    cout<<"\n Deletion success \n ";
    }
    else if(temp->left==NULL && temp->right!=NULL)
    {
    if(parent==NULL)
    root=temp->right;
    else if( parent->left==temp)
    parent->left=temp->right;
    else if(parent->right==temp)
    parent->right=temp->right;
    delete temp;
    cout<<"\n Deletion success \n ";
}

else if(temp->left!=NULL && temp->right!=NULL)
  {
if(temp->right->left==NULL)
{
temp->right->left=temp->left;
delete temp;
return;
}
cout<<"\n entered in right loop \n ";
node<T> *p;
parent=temp;
p=temp->right;
while(p->left!=NULL)
{
parent=p;
p=p->left;
}
if(p->right==NULL)
parent->left=NULL;
else
parent->left=p->right;
temp->data=p->data;
delete p;
cout<<"\n Deletion success \n ";
  }
}
}

template<class T>
 void BST<T>::display()
 {
    cout<<"\n 1.Inorder   2.Preorder   3.Postorder  \nEnter Your Choice:";
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
void BST<T>::inorder(node<T> *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    cout<<"   "<<p->data;
    inorder(p->right);

}
template<class T>
void BST<T>::preorder(node<T> *p)
{
    if(p==NULL)
        return;
    cout<<"  "<<p->data;
    preorder(p->left);
    preorder(p->right);

}
template<class T>
void BST<T>::postorder(node<T> *p)
{
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout<<"   "<<p->data;


}
int main()
{
    BST<int> ob;
    int ch;
    while(1)
    {
    cout<<"\n1.INSERT  2.REMOVE 3.DISPLAY  4.EXIT \nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
case 1:
    ob.insert();
    break;
case 2:
    ob.remove();
    break;
case 3:
    ob.display();
    break;
case 4:
    return 0;
    }
}
}
