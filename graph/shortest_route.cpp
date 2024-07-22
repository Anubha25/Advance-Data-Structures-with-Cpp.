//shortest route from Node A to B Unweighted graph.
//Graph Implemented through Adjacency list (unweighted directed/undirected)
#include<iostream>
#include<list>
#include<string>
#include<unordered_set>
#include<queue>
#include<unordered_map>
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
void shortest_route(int src, int dest,unordered_set<int> &visited)
{ 
  queue<int> queue1; unordered_map<int,int> parent;
  visited.clear(); visited.insert(src); //[0]
   queue1.push(src);           //[0]        
    while(!queue1.empty())  
      {
        for(auto i:graph[queue1.front()])   // to go through each value of key
          if(not visited.count(i))
            {
              visited.insert(i);
              queue1.push(i);
              parent.insert(make_pair(i,queue1.front()));   // to not overwrite  again.
            }
        queue1.pop(); 
      }
  vector<int> route;
  route.push_back(dest);
  while(true)               ///we are creating a hashmap for parents and child reference to backtrack 
  {
    if(dest==src)
      break;
      dest=parent[dest];
      route.push_back(dest);
  }
      for(int i = route.size()-1;i>=0;i--)
      {  cout<<route[i];
      if(i>0)
        cout<<"->"; }
      cout<<endl;
}

int main()
{ int v,n;
 cout<<"Enter the Number of vertex required in the graph ";
cin>>v;
bool un_dir;
cout<<"press 1 for undirected and 0 for directed graph:";
cin>>un_dir;
graph.resize(v,list<int> ());
cout<<"Press 1 to add egde between 2 nodes, 2 to display graph,Press 3 for shortest route from Node A to B: ";
cin>>n;
while(n!=0)
{ int src,dest;unordered_set<int> visited;
    if(n==1)
    { 
       cout<<"source :";
       cin>>src;
       cout<<"Destination :";
       cin>>dest;
       addedge(src,dest,un_dir); }
    else if(n==2)
      display();
      else if(n==3)
      {
       cout<<"Enter source :";
       cin>>src;
       cout<<"Enter Destination :";
       cin>>dest;
       shortest_route(src,dest,visited);    
      }
  cout<<"Press 1 to add egde between 2 nodes, 2 to display graph,Press 3 for shortest route from Node A to B: ";
  cin>>n;
}

}

