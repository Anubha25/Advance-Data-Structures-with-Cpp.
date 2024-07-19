//weighted directed and undirected Graph with adjacency list
// following code will not work in c++ 17 or below

#include<iostream>
#include<list>
#include<string>
#include<vector>
using namespace std;
vector<list<pair<int,int> > >graph;
void addegde(int src, int dest,int weight, bool un_dir)
{ 
    if(src>graph.size()-1 and dest >graph.size()-1)
      return;
 graph[src].push_back({weight,dest});
 if(un_dir)
 graph[dest].push_back({weight,dest});
}
void display()
{
    for(int i =0;i<graph.size();i++)
    { cout<<i<<" :";
     for(auto k :graph[i])
       cout<<" ("<<k.first<<")-->"<<k.second;
     cout<<endl;
    }
}

void bfs()
{

}
void dfs()
{

}
int main()
{ int v,n;
  bool undir;
 
    cout<<"Enter the number of Vertex Required :";
    cin>>v;
    graph.resize(v,list<pair<int,int> > ());
    cout<<"Press 1 for UnDirected and 0 for Directed :";
    cin>>undir;
    cout<<"Press 1 to addegde, 2 to display, 3 to DFS, 4 for BFS :";
    cin>>n;
    while(n!=0)
  {
    if(n==1)
    { int src,dest,wt;
       cout<<"source :";
       cin>>src;
       cout<<"Destination :";
       cin>>dest;
       cout<<"weight :";
       cin>>wt;
        addegde(src,dest,wt,undir); }
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