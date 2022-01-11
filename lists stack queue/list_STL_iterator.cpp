//To demonstrate list and iterator STLs.
#include <iostream> 
#include <list> 
#include <iterator> 
using namespace std; 
void display(list <int> L) 
{ 
    list <int> :: iterator it; 
    for(it = L.begin(); it != L.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
int main()
{
	int ch,x,p;
	list <int> ob;
	while(1)
	{
		cout<<endl<<"1.Insert at begin"<<endl<<"2.Insert at end";
		cout<<endl<<"3.Remove at begin"<<endl<<"4.Remove at end";
		cout<<endl<<"5.Reverse the List"<<endl<<"6.Sort the List";
		cout<<endl<<"7. First and Last Elements";
		cout<<endl<<"8.Display"<<endl<<"9.Exit"<<endl<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.push_front(x);
					break;
			case 2:cout<<endl<<"Enter an element to insert:";
					cin>>x;
					ob.push_back(x);
					break;
			case 3:	ob.pop_front();
					break;
			case 4:ob.pop_back();
					break;
			case 5:ob.reverse();
					cout<<"\n Reversed List is:";
					display(ob);
					break;
			case 6:ob.sort();
					cout<<"\n Sorted List is:";
					display(ob);
					break;
			case 7:cout<<"\nFirst Element in List is:"<<ob.front();
					cout<<"\nLast Element in List is:"<<ob.back();
					break;
			case 8:cout<<"\nList Elements are:";
					display(ob);
					break;
			case 9:return 0;
			default:cout<<endl<<"WRONG CHOICE";
		}
	}
}















