#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *prev,*next;
};
struct node *head=NULL,*p,*temp,*cur;
void createnode();
void insert();
void remove1();
void display();
int main()
{
    int cont,choice;
    printf("\nMain Menu");
    printf("Choice 1: Insert    2: Remove    3. Display\n");
    do{
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert();
                    break;
            case 2:remove1();
                    break;
            case 3:display();
                    break;
            default: printf("Invalid choice\n");        
        }
        printf("\n Do you want to continue , enter 1 otherwise any number\n");
        scanf("%d",&cont);
    }while(cont==1);
    return 0;
}
void createnode()
{
 int x;
 cur=(struct node*)malloc(sizeof(struct node));
 printf("ENTER THE NODE DATA ELEMENT\n");
 scanf("%d",&x);
 cur->data=x;
 cur->prev=NULL;
 cur->next=NULL;
}
void display()
{
 printf("PRINTING the elements in the list\n");
 temp=head;
 while(temp!=NULL)
 {
 printf("%d\n",temp->data);
 temp=temp->next;
 }
}
void insert()
{
    int pos,i;
    createnode();
    printf("Enter  position\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        cur->next=head;
		head=cur;
    }
    else{
	for(i=1,p=head;i<pos-1 && p!=NULL;i++)
			p=p->next;
	if(i==pos-1)
	{
		cur->next=p->next;
        cur->prev=p;
		p->next=cur;
        p->next->prev=cur;
	}
	else printf("Position does not exist\n");
    }
}
void remove1()
{
    int pos,i;
    printf("Enter  position\n");
    scanf("%d",&pos);
    p=head;
    if(head==NULL) 
	{
		printf("Linked list is empty\n");
	}
    if(pos==1)
    {
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    else{
		for(i=1,p=head;i<pos-1 && p!=NULL;i++)
			p=p->next;
		if(i==pos-1)	
		{
			p->next->prev=p->prev;
			p->prev=p->next;
			free(p);
		}
		else printf("Position does not exist\n");
    }
    
}