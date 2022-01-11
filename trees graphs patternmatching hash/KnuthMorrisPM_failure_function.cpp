#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> computeFailFunction(const string& pattern) 
{
	vector<int> fail(pattern.size());
	fail[0] = 0;
	int m = pattern.size();
	int j = 0;
	int i = 1;
	while (i < m) 
	{ 
		if (pattern[j] == pattern[i]) 
		{ // j + 1 characters match
			fail[i] = j + 1;
			i++; j++;
		}
		else if (j > 0) // j follows a matching prefix
			j = fail[j - 1];
		else 
		{ // no match
			fail[i] = 0;
			i++;
		}
	}
	cout<<endl<<"fail values are:\n";
	for(i=0;i<m;i++)
		cout<<pattern[i]<<"-->"<<fail[i]<<endl;	
	return fail;
}

int KMPmatch(const string& text, const string& pattern) 
{ 
	int n = text.size();
	int m = pattern.size();
	vector<int> fail = computeFailFunction(pattern);
	int i = 0; // text index
	int j = 0; // pattern index
	while (i < n) 
	{ 
		if (pattern[j] == text[i]) 
		{ 
			if (j == m - 1)
				return i - m + 1; // found a match
			i++; j++;
		}
		else if (j > 0) 
			j = fail[j - 1];
		else i++;
	}
	return -1; // no match
}
int main()
{
	string Text,Pattern;
	cout<<endl<<"Enter the TEXT:";
	cin>>Text;
	cout<<endl<<"Enter the PATTERN:";
	cin>>Pattern;
	int m=KMPmatch(Text,Pattern);
	if(m==-1) cout<<"\nNo Match";
	else cout<<"\n Match at index"<<m;
	return 0;
}
