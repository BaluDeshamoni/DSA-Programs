#include<iostream>
#include<math.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

class heap
{
	public:
	int *H;
	int ms,l,i,n;
	heap()
	{
		n=-1;
		cout<<"\n enter number of levels \n";
		cin>>l;
		ms=pow(2,l)-1;
		H=new int[ms];
	}
	void insert();
	void display();
	void remove();
	void hsort();
};
void heap::insert()
{
	if(n==ms-1)
		cout<<"\n *** Cannot perform insertion, Overflow   *** \n";
	else
	{
		cout<<"\n enter value \n";
		cin>>H[++n];
		int i=n;
		//Heapify operation bottom to top,
		//check with parent recursively till you reach root
		while(i>0)
		{
			if(H[i]>H[(i-1)/2])
			{
				swap(&H[i],&H[(i-1)/2]);
				i=(i-1)/2;
			}
			else
// as child is already less than parent, no more iteration is required
					break;
		}
		cout<<"\n Insertion Success \n";
	}
}


void heap::remove()
{
	if(n==-1) // no node
		cout<<"\n cannot delete \n";
	else if(n==0) // has only one node
	{
		n=-1;
		cout<<"\n Deletion success \n";
	}
	else
	{
		int temp=H[0];
		H[0]=H[n--];
		//Heapify from top to bottomn, check largest of three numbers
		int i=0;
		while(i<=n)
		{
			if(2*i+1>n) // node has no children , reached leaf node
				break;
			else  // means node has left child
			{
				if((2*i+2)<=n) // has left as well as right child
				{
					if(H[i]>H[(2*i+1)] && H[i]>H[(2*i+2)] )
// no further iteration required as parent greater than
//left and right childs
								break;
					else if(H[(2*i+1)]>H[(2*i+2)])
					{
							swap(&H[i],&H[(2*i+1)]);
							i=2*i+1;
					}
					else if(H[(2*i+1)]<H[(2*i+2)])
					{
							swap(&H[i],&H[(2*i+2)]);
							i=2*i+2;
					}

				}
				else
// if node has no right child and has only left child
				{
					if(H[i]<H[(2*i+1)])
					{
						swap(&H[i],&H[(2*i+1)]);
						i=2*i+1;
					}
					else
    						break;
// no further iteration require as parent greater than child value
				}
			} // else closed
		} // while loop closed
		cout<<endl<<temp<<"  Deletion success \n";
	} // else closed ( outside while )
} // function closed

void heap::display()
{
	if(n==-1)
		cout<<"\n cannot display , no elements \n";
	else
	{
		cout<<"\n The nodes in Tree are \n";
		for(int i=0;i<=n;i++)
    		cout<<"   "<<H[i];

	}
}

void heap::hsort()
{
	int i,temp,n1=n;
	for(i=0;i<n1;i++)
	{
		temp=H[0];
		remove();
		H[n+1]=temp;
	}
	cout<<"\n Elements after Sorting are \n";
	for(i=0;i<=n1;i++)
		cout<<"  "<<H[i];
	n=-1;
}
int main()
{
    heap h;
    while(1)
    {
        cout<<"\n 1.insert  2.remove  3.display  4.sort   5.Exit \nEnter Your Choice:\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            h.insert();
            break;
        case 2:
            h.remove();
            break;
        case 3:
            h.display();
            break;
        case 4:
        	h.hsort();
        	break;
        case 5:
            return 0;
        }

    }

}





