//Disjoint set Union by SIZE 
//at every Union we add up the size[u]=size[u]+size[v]  to update u.

#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int> >graph;
class disjoint
{
vector<int> parent;
vector<int> sizee;
public:
disjoint(int n)
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
{   if(u==v)
     return true;
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
void addedge(int src, int dest,bool un_dir=true)
{ if (src>=graph.size()-1 or dest>=graph.size()-1 or src==dest)
    return;

    for(int i:graph[src])
       if(i==dest)
         return;
  graph[src].push_back(dest);
  if(un_dir)
  graph[dest].push_back(src);
}
void display()
{
    for(int i =0;i<graph.size();i++)
    {cout<<i<<" :";
        for(auto k:graph[i])
        cout<<k<<" ";
      cout<<endl;}
}
int main()
{
int n;
cout<<"Size of graph :";
cin>>n;
graph.resize(n+1);
disjoint *set = new disjoint(n+1);
cout<<"Press 1 to add edge, 2 to display :";
cin>>n;
while(n!=0)
{ int src,dest;
if(n==1)
{   cout<<"src";
    cin>>src;
    cout<<"dest";
    cin>>dest;
    addedge(src,dest,true);
    if(!set->Union(src,dest))
        cout<<"\n CYCLE EXIST AT "<<src<<" "<<dest<<endl;
}
else if(n==2)
  display();

cout<<"Press 1 to add edge 2 to display:";
cin>>n;
}
}

