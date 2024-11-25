#include <bits/stdc++.h>
using namespace std;
int adj[100][100];
bool visited[100];

void dfs(int start,int n)
 {
     stack<int>s;
     s.push(start);
     visited[start]=true;

     while(!s.empty())
     {
         int current_node=s.top();
         s.pop();
         cout<<current_node<<" ";

         for(int i=0;i<n;i++)
         {
             if(adj[current_node][i]==1 && !visited[i])
             {
                 visited[i]=true;
                 s.push(i);
             }
         }
     }
 }
 int main()
 {
     int n,e;
     cout<<"Enter the number of vertices(n) and edges(e):"<<endl;
     cin>>n>>e;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             adj[i][j]=0;
         }
     }
     int u,v;
     cout<<"Enter edges(u)(v):"<<endl;
     for(int i=0;i<e;i++)
     {
         cin>>u>>v;
         adj[u][v]=adj[v][u]=1;
     }

     cout << "DFS Traversal starting from vertex 0: ";
    dfs(0,n);

 }
