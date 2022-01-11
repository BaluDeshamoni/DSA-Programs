//program to implement quick sort technique
#include<iostream>
using namespace std;
void quicksort(int a[],int low,int high);
int partitionarr(int a[],int low,int high);
int main()
{
    int a[10],n;
    cout<<"Enter the size of the array less than 10 :"<<endl;
    cin>>n;
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"  ";
 return 0;
}
void quicksort(int a[],int low,int high)
{
    int i;
    if(low<high)
    {
        i=partitionarr(a,low,high);
        quicksort(a,low,i-1);
        quicksort(a,i+1,high);
    }
}
int partitionarr(int a[],int low,int high)
{
    int p=high,k=low-1;
    for(int i=low;i<p;i++)
    {
        if(a[i]<a[p])
        {
            k++;
            swap(a[k],a[i]);
        }
    }
    swap(a[k+1],a[p]);
    return k+1;
}

