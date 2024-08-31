#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int> > graph;
void addedge(int src,int dest,int undir)
{
    graph[src].push_back(dest);
    if(undir)
    graph[dest].push_back(src);
}
void display()
{
 for(int i =0;i<graph.size();i++)
  { cout<<i<<" :";
    for(int j : graph[i])
     cout<<j<<" ";
    cout<<endl;}
}
void bfs(int src)
{
    unordered_set<int> visited;
    queue<int> queue1;
    queue1.push(src);
    cout<<endl;
    visited.insert(src);
    while(!queue1.empty())
    {
        int front =queue1.front();
        cout<<front<<" ";
        queue1.pop();
        for(auto m: graph[front])
          if(!visited.count(m))
            {visited.insert(m);queue1.push(m);}
    }
}
void Topological()  //if cycle exist the sorting will fail.
{ int n = graph.size();
vector<int> indegree(n,0);
queue<int> queue1;

 for(int i =0;i<graph.size();i++)
    for(auto m:graph[i])
       indegree[m]++;

for(int i =0;i<n;i++)
  if(indegree[i]==0)
   {
     queue1.push(i);
     indegree[i]--;
   }

vector<int> sequence;
while(!queue1.empty())
{
  int front= queue1.front();
  queue1.pop();
  sequence.push_back(front);
  for(auto m:graph[front])
    {   indegree[m]-=1;
     if(indegree[m]==0)
       queue1.push(m);
    }
}
if(sequence.size()==n)
  cout<<"CYCLIC GRAPH";
else
  for(int i =0;i<sequence.size();i++)
     cout<<sequence[i]<<" ";

}
int main()
{
int n,undir=0;
cout<<"Enter the Vertices size :";
cin>>n;
cout<<"Press 1 for Undir and 0 for dir :";
cin>>undir;
graph.resize(n+1);
cout<<"Press 1 to Addedge, 2 to display, 3 for BFS, 4 for Topological sorting :";
cin>>n;
addedge(1,2,0);
addedge(1,5,0);
addedge(2,3,0);
addedge(2,4,0);
addedge(4,3,0);
addedge(4,5,0);
addedge(6,3,0);
while(n!=0)
{ int src,dest;
 if(n==1)
 {
    cout<<"SOURCE :";
    cin>>src;
    cout<<"Dest :";
    cin>>dest;
    addedge(src,dest,undir);
 }
 else if(n==2)
    display();
 else if(n==3)
   {
    cout<<"SOURCE :";
    cin>>src;
    bfs(src);
   }
 else if(n==4)
  Topological();
cout<<"Press 1 to Addedge, 2 to display, 3 for BFS, 4 for Topological sorting :"<<endl;
cin>>n;
}

}