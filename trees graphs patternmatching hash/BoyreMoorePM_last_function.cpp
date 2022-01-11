#include<iostream>
#include<string>
#include<vector>
using namespace std;

// construct function last
std::vector<int> buildLastFunction(const string& pattern) 
{ 
	const int N_ASCII = 128; // number of ASCII characters
	int i;
	vector<int> last(N_ASCII); // assume ASCII character set
	for (i = 0; i < N_ASCII; i++) // initialize array
		last[i] = -1;
	for (i = 0; i < pattern.size(); i++) 
	{ 
		last[pattern[i]] = i; // (implicit cast to ASCII code)
		cout<<endl<<pattern[i]<<" last value is:"<<last[pattern[i]];
	}
	return last;
}

int BMmatch(const string& text, const string& pattern) 
{ 
	vector<int> last = buildLastFunction(pattern);
	int n = text.size();
	int m = pattern.size();	
	int i = m - 1;
	if (i > n - 1) // pattern longer than text?
		return -1; // . . .then no match
	int j = m - 1;
	do 
	{   
		//use this statement to trace the code
	    //cout<<endl<<"compare text("<<i<<") "<<text[i]<<" and pattern("<<j<<") "<<pattern[j];
		if (pattern[j] == text[i])
		{	
			if (j == 0) return i; // found a match
			else 
			{ // looking-glass heuristic
				i--; j--; // proceed right-to-left
			}
		}
		else 
		{ // character-jump heuristic
			i = i + m - min(j, 1 + last[text[i]]);
			j = m - 1;
			cout<<endl;
		}
	} while (i <= n - 1);
	return -1; // no match
} 


int main()
{
	string Text,Pattern;
	cout<<endl<<"Enter the TEXT:";
	cin>>Text;
	cout<<endl<<"Enter the PATTERN:";
	cin>>Pattern;
	int m=BMmatch(Text,Pattern);
	if(m==-1) cout<<"\nNo Match";
	else cout<<"\n Match at index"<<m;
	return 0;
}
