/*string STL had following functions
size(): Return the number of characters, n, of S.
empty(): Return true if the string is empty and false otherwise.
operator[i]: Return the character at index i of S, without performing
array bounds checking.
at(i): Return the character at index i of S. An out of range
exception is thrown if i is out of bounds.
insert(i,Q): Insert string Q prior to index i in S and return a reference
to the result.
append(Q): Append string Q to the end of S and return a reference to
the result.
erase(i,m): Remove m characters starting at index i and return a reference
to the result.
substr(i,m): Return the substring of S of length m starting at index i.
find(Q): If Q is a substring of S, return the index of the beginning
of the first occurrence of Q in S, else return n, the length
of S.
c str(): Return a C-style string containing the contents of S.

*/
/*brute force pattern matching technique*/
#include<string>
#include<iostream>
using namespace std;
void BruteForce(string T , string P)
{
	int n=T.length();                             // length of text
	int m=P.length();                             // length of pattern
	int i,j;	
	for(.i++)   // Iteration over n-m+1 values of shift
	{             
		for(j=0;j<m;j++)                
			if(T[i+j]!=P[j]) 
				break;
		
		if(j==m) 
			cout<<"Pattern found at : "<<i+1<<endl;
	}
}
int main()
{
	string Text,Pattern;
	cout<<endl<<"Enter the TEXT:";
	cin>>Text;
	cout<<endl<<"Enter the PATTERN:";
	cin>>Pattern;
	BruteForce(Text,Pattern);
	return 0;
}
