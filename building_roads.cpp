#include <bits/stdc++.h>
using namespace std;
const int E=1e5+5;
int parent[E];
int parentLevel[E];

void dsu_set(int n){
    for (int i = 0; i <=n; i++)
    {
        parent[i]=-1;
        parentLevel[i]=1;
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
    if(leaderA != leaderB){
        if(parentLevel[leaderA] > parentLevel[leaderB]){
        parent[leaderB]=leaderA;
        }else if (parentLevel[leaderA] < parentLevel[leaderB])  
        {
            parent[leaderA]=leaderB;
        }else{
            parent[leaderB]=leaderA;
            parentLevel[leaderA]++;
        }
    
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
    
    map<int,bool> mp;
    for (int i = 1; i <=n; i++)
    {
        int ldr=dsu_find(i);
        mp[ldr] = true;
    }
    vector<int>v;
    for(pair<int, bool>p:mp){
        v.push_back(p.first);
    }
    cout<<v.size()-1<<endl;

    for (int i = 0; i < v.size()-1; i++)
    {
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    
    
    return 0;
}