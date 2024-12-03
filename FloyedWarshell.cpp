#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int path[100][100];
void printPath(int s,int d)
{
    if(s==d)
    {
        cout<<d<<" ";
    }
    else{
        printPath(s,path[s][d]);
        cout<<d<<" ";
    }

}

int main()
{
    int n,e;
    cout<<"Enter vertex and edge: ";
    cin>>n>>e;

    int dist[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
                path[i][j]=i;
            }
            else
            {
                dist[i][j]=INF;
                path[i][j]=-1;
            }
        }
    }

    int u,v,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        dist[u][v]=w;
        path[u][v]=u;
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j]>dist[k][j]+dist[i][k])
                {
                    dist[i][j]=dist[k][j]+dist[i][k];
                    path[i][j]=path[k][j];
                }
            }
        }
    }

    cout<<"Distance matrix: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<"INF";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    int s,d;
    cin>>s>>d;
    cout<<"Shortest path: ";
    printPath(s,d);
    cout<<"Cost: "<<dist[s][d];



}
