#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *left,*right;
};
struct node *first=NULL,*last,*cur,*temp,*prev;
void createnode();
void createlist();
void display();
void countnode();
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
int main()
{
	 int choice=0;
 while(choice!=10)
 {
 printf("\nMain Menu");
 printf("\nChoose one option...");
 printf("\n 1.create the list ");
 printf("\n 2.display the list ");
 printf("\n 3.count the nodes ");
 printf("\n 4.inserting a node at the beginning ");
 printf("\n 5.inserting a node at the end ");
 printf("\n 6.inserting a node at a certain position ");
 printf("\n 7.deleting a node at the beginning ");
 printf("\n 8.deleting a node at the end ");
 printf("\n 9.deleting a node at the certain position ");
 printf("\n 10.exit ");
 printf("\nEnter your choice\n");
 scanf("%d",&choice);
 switch(choice)
 {
    case 1:
        createlist();
        break;
   case 2:
        display();
        break;
   case 3:
        countnode();
        break;
   case 4:
        insertbeg();
        break;
   case 5:
        insertend();
        break;
   case 6:
        insertpos();
        break;
  case 7:
        deletebeg();
        break;
  case 8:
        deleteend();
        break;
  case 9:
        deletepos();
        break; 
  case 10:
       exit(0);
       break;
  default:
       printf("Wrong choice\n");
       break;
 }
 }
}
void createnode()
{
 int x;
 cur=(struct node*)malloc(sizeof(struct node));
 printf("ENTER THE NODE DATA ELEMENT\n");
 scanf("%d",&x);
 cur->data=x;
 cur->left=NULL;
 cur->right=NULL;
}
void createlist()
{
 createnode();
 if(first==NULL)
 {
 first=cur;
 last=cur;
 }
 else
 {
 last->right=cur;
 cur->left=last;
 last=cur;
 }
}
void display()
{
 printf("PRINTING the elements in the list\n");
 temp=first;
 while(temp!=NULL)
 {
 printf("%d\n",temp->data);
 temp=temp->right;
 }
}
void countnode()
{
 int c=0;
 temp=first;
 while(temp!=NULL)
 {
 c++;
 temp=temp->right;

 }
 printf("The number of nodes are %d\n",c);
}
void insertbeg()
{
 createnode();
 cur->right=first;
 first->left=cur;
 first=cur;
}
void insertend()
{
 createnode();
 last->right=cur;
 cur->left=last;
 last=cur;
}
void insertpos()
{
 createnode();
 int c=1,pos;
 printf("Enter position to insert a node \n");
 scanf("%d",&pos);
 temp=first;
 while(c<pos)
 {
 	 prev=temp;
 temp=temp->right;
 c++;
 }
 cur->right=prev->right;
 prev->right=cur;
}
void deletebeg()
{
 temp=first;
 first=first->right;
 temp->left=NULL;
 temp->right=NULL;
 first->left=NULL;
 free(temp);
}
void deleteend()
{
 temp=last;
 last=last->left;
 last->right=NULL;
 temp->left=NULL;
 temp->right=NULL;
 free(temp);
}
void deletepos()
{
 int pos,c=1;
 printf("Enter position to delete a node\n");
 scanf("%d",&pos);
 temp=first;
 while(c<pos)
 {
 prev=temp;
 temp=temp->right;
 c++;
 }
 temp->right->left=prev;
 prev->right=temp->right;
 temp->right=NULL;
 temp->left=NULL;
 free(temp);
}

