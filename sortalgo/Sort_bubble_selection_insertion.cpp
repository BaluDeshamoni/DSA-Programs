#include<iostream>
#include<list>
#include<cmath>
using namespace std;
void swap(int &a, int &b)
{
	int c=a;
	a=b;
	b=c;
}
void readArray(int *A, int n)
{
	cout<<endl<<"Enter "<<n<<" number of elements";
	for(int i=0;i<n;i++)
		cin>>A[i];
}
void displayArray(int *A, int n)
{
	cout<<endl<<"Array Elements are:";
	for(int i=0;i<n;i++)
		cout<<"  "<<A[i];
	cout<<endl;
}
void selectionSort(int *A, int n) 
{
   for (int i = 0; i < n-1; i++) 
   {
    	int min = i;
    	for (int j = i+1; j < n; j++)
       		if (A[j] < A[min]) 
				min = j;
    	//swap ith element with minimum element
		swap(A[i], A[min]);
  }
}
void insertionSort(int *A, int n) 
{
   for (int i = 1; i < n; i++)
   { 
      int tmp = A[i]; // the element to be inserted
      int j;
      for (j=i; j>0 && tmp<A[j-1]; j--)// shift elements
         A[j] = A[j-1]; 
         
      A[j] = tmp; // insert the element
   }
}
void bubbleSort(int *A, int n) 
{
   for (int i = 0; i < n-1; i++) 
   {
    	for (int j = 0; j < n-i-1; j++)
       		if (A[j] > A[j+1]) 
				swap(A[j], A[j+1]);
  }
}
int main() {
   int n, max;
   cout << "Enter the number of elements: ";
   cin >> n;
   int A[n]; //create an array with given number of elements
   readArray(A,n);
   cout << "\nData before Sorting: ";
   displayArray(A, n);
   bubbleSort(A, n);
   //selectionSort(A, n);
   //insertionSort(A, n);
   cout << "\nData after Sorting: ";
   displayArray(A, n);
}
