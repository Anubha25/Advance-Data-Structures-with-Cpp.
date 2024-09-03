#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
vector<list<int> >graph;
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
bool Bipartite(int src)
{
    int n = graph.size();
    vector<int> visited(n+1,-1);
    queue<pair<int,int> >queue1;
    visited[src]=0;
    queue1.push({src,0});
    while(!queue1.empty())
    {
        int src = queue1.front().first;
        int color= queue1.front().second; 
        queue1.pop();
        cout<<src<<"->"<<color<<" ";
        for(int m : graph[src])
        {  if(visited[m]==-1)
           { visited[m]=!color;
            queue1.push({m,visited[m]}); }
           else if(visited[m]==color)
             return true;
        }
    }
    return false;
}

int main()
{
int v,n;
 cout<<"Enter the Number of vertex required in the graph ";
cin>>v;
bool un_dir;
cout<<"press 1 for undirected and 0 for directed graph:";
cin>>un_dir;
graph.resize(v,list<int> ());
cout<<"Press 1 to add egde, 2 to display graph,Press 3 to check bipartite: ";
cin>>n;
while(n!=0)
{  int src,dest;
    if(n==1){
    cout<<"source :";
    cin>>src;
    cout<<"Destination :";
    cin>>dest;
    addedge(src,dest,un_dir); 
    }
    else if(n==2)
      display();
    else if(n==3)
     { cout<<"Enter source :";
       cin>>src;
       if(Bipartite(src))
         cout<<"\n Graph is Not a bipartite ";
        else
        cout<<"\n Graph is a bipartite ";
     }
cout<<"Press 1 to add egde, 2 to display graph,Press 3 to check bipartite: ";
cin>>n;
}
}