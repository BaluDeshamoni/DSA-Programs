/*Quick Sort using Array */
#include <iostream>
using namespace std;
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
void quickSort(int *A,int low,int high);
int partition(int *A,int low,int high);
int main()
{
    int A[100],n,i;
    cout<<"\nEnter Number of elements:";
    cin>>n;
    readArray(A,n);
    displayArray(A,n);
	quickSort(A,0,n-1);
    cout<<"\nAfter sorting:";
    displayArray(A,n);
	return 0;        
}
void quickSort(int A[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(A,low,high); // j is the pivot position to divide the set
        quickSort(A,low,j-1);   //quick sort recursive call for left (less than pivot) 
        quickSort(A,j+1,high);  //right (greater than pivot) parts
    }
}
int partition(int A[],int low,int high)
{
    int pivot,i,j,temp;
    pivot=A[low];
    i=low+1;
    j=high;
    while(i<=j)  // till i did not cross j
    {
    	while(A[i]<pivot && i<=high)  //increment i till greater element occurs
    		i++;
    	while(A[j]>pivot && j>low) //decrement j till smaller element occurs
    		j--;
    	if(i<j)       //if i did not cross j then swap
   		{
    		int temp=A[j];
    		A[j]=A[i];
    		A[i]=temp;
    	}
	}
	
    A[low]=A[j];  //swapping pivot and jth element
    A[j]=pivot;
    return j; // return j to know appropriate pivot position
}
