#include<bits\stdc++.h>
using namespace std;
int main()
{
    int a[10],t,p,j;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<5;i++)
    {
        t=a[i];
        p=i;
        for( j=i-1;j>=0;j--)
        {
            if(t<a[j])
                a[p--]=a[j];
        }
            a[p]=t;
    }
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;
    return 0;
}
