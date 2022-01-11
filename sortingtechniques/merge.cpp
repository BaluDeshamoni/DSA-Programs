#include<bits\stdc++.h>
using namespace std;
void mergesort(int a[],int l,int h);
void mergearr(int a[],int l,int m,int h);
int main()
{
    int a[10];
    for(int i=1;i<7;i++)
        cin>>a[i];
    mergesort(a,1,6);
    for(int i=1;i<7;i++)
        cout<<a[i]<<endl;
    return 0;
}
void mergesort(int a[],int l,int h)
{
    int m;
    if(l<h)
    {
        m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        mergearr(a,l,m,h);
    }
}
void mergearr(int a[],int l,int m,int h)
{
    int n1,n2,x=0,y=0,z=l;
    n1=m-l+1;
    n2=h-m;
    int b[n1],c[n2];
    for(int i=0;i<n1;i++)
        b[i]=a[l+i];
    for(int i=0;i<n2;i++)
        c[i]=a[m+i+1];

    while(x<n1&&y<n2)
    {
        if(b[x]<=c[y]){
            a[z]=b[x];
            x++;
        }
        else{
            a[z]=c[y];
            y++;
        }
        z++;
    }
    while(x<n1)
    {
          a[z]=b[x];
          z++;
          x++;
    }
    while(y<n2)
    {
          a[z]=c[y];
          z++;
          y++;
    }
}
