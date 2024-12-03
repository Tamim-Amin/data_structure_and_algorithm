#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<high)
        {
            i++;
        }
        while(a[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[low],a[j]);
    return j;
}
void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quickSort(a,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
