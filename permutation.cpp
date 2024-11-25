#include <bits/stdc++.h>
using namespace std;


void permutation(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
      cout<<a[i]<<" ";
  }
  cout<<endl;

}
void permute(int a[],int start,int n)
{
    if(start==n)
    {
        permutation(a,n);
        return;
    }

    for(int i=start;i<n;i++)
    {
        swap(a[start],a[i]);
        permute(a,start+1,n);
        swap(a[start],a[i]);
    }
}
int main()
{
    int n;
    cout<<"Enter a numbers: ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" number:";
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }

     permute(a,0,n);
}
