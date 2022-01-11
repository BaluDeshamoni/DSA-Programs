#include <iostream>
using namespace std;
class Hash
{
	int *ht;
	bool *chk;
	int x;

public:
	Hash(int size)
	{
		x = size;
		ht = new int[x];   //array of buckets
		chk = new bool[x]; // array to check weather the buckets are filled or not;
		for (int i = 0; i < x; i++)
		{
			ht[i] = 0;
			chk[i] = true;
		}
	}
	void insert(int a)
	{
		int i = a % x; //hashing funcion for the given element
		if (chk[i])
		{
			ht[i] = a;
			chk[i] = false;
		}
		else
		{
			int j = (i + 1) % x; // in case if array filled we will use this to insert ele in next spac
			if (chk[j])
			{
				ht[j] = a;
				chk[j] = false;
				return;
			}
			else
			{
				if (j != i)
				{
					cout << "hash table is full";
				}
			}
		}
	}
	int search(int a) // to search if an elemnt is found in an array or not
	{
		int i = a % x;
		int j = i;
		while (i != j)
		{
			if (ht[i] == a && !chk[i])
			{
				i = (i + 1) % x;
				return i;
			}
			else
			{
				return -1;
			}
		}
	}
	void display()
	{
		cout << "Elememt of Hash table : " << endl;
		for (int i = 0; i < x; i++)
		{
		    if(ht[i]!=0)
			cout << ht[i] << "\t";
		}
	}
};
int main()
{
	int element, ch, a;
	Hash obj(10);
	while (1)
	{
		cout<<"\n\n\t\tMENU";
		cout<<"\n1. insert 1 or more ele into hashtable"<<"\n2. search an ele in the hash table"<<"\n3. display the hash table"<<"\n4. exit\n";
		cout<<"Enter your choice:  ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter element : " << endl;
			cin >> element;
			obj.insert(element);
			break;
		case 2:
			cout << "Enter element to be searched : " << endl;
			cin >> element;
			a = obj.search(element);
			if (a != -1)
			{
				cout << "Element is found in position : " << a; //a+1
			}
			else
			{
				cout << "element not found";
			}
			break;

		case 3:
			obj.display();
			break;
		case 4:
			return 0;
		}
	}
}
