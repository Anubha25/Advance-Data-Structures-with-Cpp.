//Graph Implemented through Adjacency list (unweighted directed/undirected)
#include<iostream>
#include<list>
#include<string>
#include<unordered_set>
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
bool find(int src,int dest,unordered_set<int> &visited){
    if(src==dest)
       return true;
    visited.insert(src);
    bool result=1;
    list<int> tmp = graph[src];
    for(auto i:tmp)
    {
        if(visited.find(i)==visited.end())
        { cout<<"src :"<<src<<" dest : "<<dest<<endl;
            if(find(i,dest,visited))
              return true;   }
    }
    return false;
}
void findpaths(int src, int dest,unordered_set<int> &visited,vector<int> route,vector<vector<int > > &main)
{  route.push_back(src); visited.insert(src);
    if(src==dest) {
      main.push_back(route); visited.erase(src); return; }
    for(auto i:graph[src])
    { 
      if(not visited.count(i))
      {
        findpaths(i,dest,visited,route,main);
      }
    } 
  visited.erase(src);
}
int main()
{ int v,n;
 cout<<"Enter the Number of vertex required in the graph ";
cin>>v;
bool un_dir;
cout<<"press 1 for undirected and 0 for directed graph:";
cin>>un_dir;
graph.resize(v,list<int> ());
cout<<"Press 1 to add egde between 2 nodes, 2 to display graph,Press 4 for all paths from sorce to destination: ";
cin>>n;

while(n!=0)
{ int src,dest;  
    if(n==1)
    { 
       cout<<"source :";
       cin>>src;
       cout<<"Destination :";
       cin>>dest;
       addedge(src,dest,un_dir); }
    else if(n==2)
      display();
    else if(n==4)
     { cout<<"Enter source :";
       cin>>src;
       cout<<"Enter Destination :";
       cin>>dest;
       vector<vector<int > > main;vector<int> route;unordered_set<int> visited;
       findpaths(src,dest,visited,route,main);
       for(int i=0;i<main.size();i++)
        { cout<<endl;
         for(int j=0;j<main[i].size();j++)
           cout<<main[i][j]<<" ";   
        } 
        cout<<endl;
      }
  cout<<"Press 1 to add egde between 2 nodes, 2 to display graph, Press 4 for all paths from sorce to destination: ";
  cin>>n;
}

}

