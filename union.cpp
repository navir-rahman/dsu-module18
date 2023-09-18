#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];

void dsu_set(int n){
    for (int i = 0; i <=n; i++)
    {
        parent[i]=-1;
        parentSize[i]=1;
    }
    
}
int dsu_find(int n){
    while (parent[n] != -1)
    {
        n =parent[n];
    }
    return n;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(parentSize[leaderA]> parentSize[leaderB])
    {
        parent[leaderB]=leaderA;
        parentSize[leaderA] += parentSize[leaderB];
    }else{
        parent[leaderA]= leaderB;
        parentSize[leaderB] += parentSize[leaderA];
    }
    
}

int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    
    cout<<dsu_find(5 );
    return 0;
}