//Graph Implemented through Adjacency list (unweighted directed/undirected)
#include<iostream>
#include<list>
#include<string>
using namespace std;
vector<list<int> > graph;
void addedge(int src, int dest,bool un_dir=true)
{ if (src>graph.size()-1 or dest>graph.size()-1)
   { cout<<"GRAPH OVER FLOW ! \n "; return;}
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
void dfs(){

}
void bfs()
{

}
int main()
{ int v,n;
 cout<<"Enter the Number of vertex required in the graph ";
cin>>v;
bool un_dir;
cout<<"press 1 for undirected and 0 for directed graph:";
cin>>un_dir;
graph.resize(v,list<int> ());
cout<<"Press 1 to add egde between 2 nodes, 2 to display graph 3 for DFS, 4 for BFS: ";
cin>>n;
while(n!=0)
{
    if(n==1)
    { int src,dest;
       cout<<"source :";
       cin>>src;
       cout<<"Destination :";
       cin>>dest;
        addedge(src,dest,un_dir); }
    else if(n==2)
      display();
    else if(n==3)
      dfs();
    else if(n==4)
     bfs();

cout<<"Press 1 to add egde between 2 nodes, 2 to display graph 3 for DFS, 4 for BFS: ";
cin>>n;
}

}

