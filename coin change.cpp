#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cout<<"Enter the number of coin:";
   cin>>n;
   int coin[n];
   cout<<"Enter the value of the coin:";
   for(int i=0;i<n;i++)
   {
       cin>>coin[i];
   }
   int a;
   cout<<"Enter the total amount of the coin: ";
   cin>>a;
   int minCoin[a+1];
   minCoin[0]=0;
   for(int i=1;i<=a;i++)
   {
       minCoin[i]=INT_MAX;
   }

   for(int i=1;i<=a;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(coin[j]<=i)
           {
               minCoin[i]=min(minCoin[i],minCoin[i-coin[j]]+1);
           }
       }
   }

   if(minCoin[a]!=INT_MAX)
   {
       cout<<"Minimum number of coin is: "<< minCoin[a];
   }
   else{
    cout<<"Not possible.";
   }
}
