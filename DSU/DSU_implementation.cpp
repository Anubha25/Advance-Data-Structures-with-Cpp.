//Disjoint set Union by SIZE 
//at every Union we add up the size[u]=size[u]+size[v]  to update u.

#include<iostream>
#include<vector>
using namespace std;
class disjointset
{
vector<int> parent;
vector<int> sizee;
public:
disjointset(int n)
{
    parent.resize(n+1);
    sizee.resize(n+1);
    for(int i=0;i<=n;i++)
    {  parent[i]=i;
        sizee[i]=1; }
}
int find(int u)
{
  if(u==parent[u])
     return u;
  return parent[u]=find(parent[u]);
}
bool Union(int u, int v)
{
    int parent_u = find(u); //1
    int parent_v = find(v); //2
    if(parent_u==parent_v)
       return false;
    if(sizee[parent_u]>=sizee[parent_v])
    {
    parent[parent_v]=parent_u;           //
    sizee[parent_u]+=sizee[parent_v];
    }
    else{
        parent[parent_u]=parent_v;
        sizee[parent_v]+=sizee[parent_u];
    }
    for(int i:parent)
     cout<<i<<" ";
    cout<<endl;
    return true;
}
};
