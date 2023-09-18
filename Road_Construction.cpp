#include <bits/stdc++.h>
using namespace std;
const int E=1e5+5;
int parent[E];
int parentSize[E];

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

int mx=0;
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(parentSize[leaderA]> parentSize[leaderB])
    {
        parent[leaderB]=leaderA;
        parentSize[leaderA] += parentSize[leaderB];
        mx=max(mx,parentSize[leaderA]);
    }else{
        parent[leaderA]= leaderB;
        parentSize[leaderB] += parentSize[leaderA];
        mx=max(mx,parentSize[leaderB]);
    }
    
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int cmp=n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leadarA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leadarA != leaderB)
        {
            cmp--;
            dsu_union(a,b);

        }
            cout<<cmp<<" "<<mx<<endl;
    }

    return 0;
}