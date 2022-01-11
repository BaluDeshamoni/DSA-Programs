/* Merge Sot Technique */
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
 
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low; // first set is low to mid
	k = 0;   
	j = mid + 1; //second set is mid+1 to high
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
    // copy the elements from temp array to original a array
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
 
int main()
{
	int A[100],n;
	cout<<"\n Enter Maximum no of elements";
	cin>>n;
	readArray(A,n);
	displayArray(A,n);
	MergeSort(A, 0, n-1);
 	// Printing the sorted data.
	displayArray(A,n);
	return 0;
}
