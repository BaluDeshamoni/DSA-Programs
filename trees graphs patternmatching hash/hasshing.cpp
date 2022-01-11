#include<iostream>
using namespace std;
const int MAX=10;
class hashtable : public node
{
	node *table[MAX];//hash table with MAX buckets
	public:
		hashtable():node()
		{
			for(int i=0;i<MAX;i++)
				table[i]=NULL;

		}
		void insert(int,int);//To insert element into hash table
		int search(int,int);//To search element from hash table
		void display();//To display the contents of bucket of hash table
};

//Function to insert elements into hash table
void hashtable::insert(int info, int pos)
{
	node *temp;
	temp=new node();
	temp->inf=info;
	if(table[pos]==NULL)
		table[pos]=temp;
	else
	{
		node *p=table[pos];
		while(p->link!=NULL)
			p=p->link;
		t->link=temp;
	}
}
//Function to search an element in the hashtable
int hashtable::search(int info,int pos,no)
{
	if(table[pos]==NULL)
		return -1;
	else
	{
	    int i=0;
		while(i<no)
        {
            if(table[pos]==info)
                return info;
                i++;
        }
		return -1;
	}
}
//Function to display the contents of a hashtable
void hashtable::display()
{
	for(int pos=0;pos<MAX;pos++)
	{
		if(table[pos]==NULL)
		{
			//cout<<"\nNo element inserted in "<<pos<<" bucket";
		}
		else
		{
			node *t=table[pos];
			cout<<"\nElements in "<<pos <<" bucket are as follows....";
			do
			{
				cout<<t->inf<<"\t";
				if(t->link==NULL)
					break;
				else
					t=t->link;
			}while(t!=NULL);
		}
	}//end of for loop
	cout<<endl;
}//end of display
int main()
{
	int ele,no,ch;
	hashtable ht;//Hashtable object
	while(1)
	{
		cout<<"\n\n\t\tMENU";
		cout<<"\n1. insert 1 or more ele into hashtable"<<"\n2. search an ele in the hash table"<<"\n3. display the hash table"<<"\n4. exit\n";
		cout<<"Enter your choice:  ";
		cin>>ch;
		switch(ch)
		{
			case 1: //To insert 1 or more element into the hashtable
			{	cout<<"Enter no. of element(s) to be inserted into hashtable:  ";
				cin >>no;
				cout<<"Enter "<<no <<" of elements"<<endl;
				for(int i=0;i<no;i++)
				{
					cout<<i <<" element = ";
					cin>>ele;
					//To avoid inserting duplicate values in the hashtable
					if(ele==ht.search(ele,ele%10,no))
						cout<<ele<<" already exists in the hash table"<<endl;
					else
						ht.insert(ele, ele%10);
				}
			}	break;
			case 2: //To search for an element
				cout<<"Enter a number to search:  ";
				cin>>ele;
				if(ele==ht.search(ele,ele%10))
					cout<<ele<<" found in bucket " <<ele%10<<endl;
				else
					cout<<"Element not found in hash table";
				break;

			case 3:	//To display the contents of the hashtable
				ht.display();
				break;

			default: //To exit()
				_exit(0);

		}//End of switch
	}//End of while
	return 0;
}//End of main
