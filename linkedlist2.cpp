//Doubly linked LIST
#include<iostream>
using namespace std;
class node
{
    public:
    node *prev=NULL;
    int val;
    node *nxt=NULL;
    node(int n)
    {
     val=n;
    }
    ~node()
    {cout<<endl;
        cout<<val<<" has been deleted"<<endl;}
};
void insert_start(node * &start, node * &end)
{   int n;
    cout<<"Enter the value to be inserted at starting:";
    cin>>n;
    node *fresh=new node(n);
    if(start==NULL)
        end=fresh;
    else
    {
        fresh->nxt=start;
        start->prev=fresh;
    }
    start=fresh; 
}
void insert_end(node * &start, node * &end)
{
    int n;
    cout<<"Enter the value to be inserted at end:";
    cin>>n;
    node *fresh=new node(n);
    if(start==NULL)
        start=fresh;
    else
    {
        end->nxt=fresh;
        fresh->prev=end;
    }
    end=fresh;
}
void insert_specific(node * &start, node * &end)
{ int n,j;
  cout<<"Enter the Position at which the Node is to be inserted:";
   cin>>n;
   if(start==NULL && n==0) //empty linked list
     return insert_start(start,end);
   if(start!=NULL && n==0) //insertion at starting
      return insert_start(start,end);
   if(start==NULL && n>0) //OVERFLOW
      {cout<<"values does not exists upto "<<n<<" position"; return;}
   if(start!=NULL &&(start==end && n==1)) //insertion at end
       return insert_end(start,end);
   node * fresh= start;
   for(int i=0;i<n;i++)
   { if(fresh->nxt==NULL && i==n-1)
          return insert_end(start,end);
    if(fresh->nxt!=NULL)
      fresh=fresh->nxt;
      else
      {cout<<"No values till "<<n<<" to be inserted \n";return;}
   } 
   cout<<"Enter the value to be inserted :";
    cin>>j;
    node *w =new node(j);
    w->prev=fresh->prev;
    fresh->prev->nxt=w;
    w->nxt=fresh;
    fresh->prev=w;
}
void traverse(node * start)
{
    while(start!=0)
    {
        cout<<start->val;
        if(start->nxt!=NULL)
           cout<<"->";
        start=start->nxt;
    }
    cout<<endl;
}
void del(node * &start, node * &end)
{ if(start!=NULL)
    delete start; start=end=NULL; 
}
void del_start(node * &start, node * &end)
{  if(start==end)
        return del(start,end);
    start=start->nxt;
    delete start->prev;
    start->prev=NULL;

}
void del_end(node * &start, node * &end)
{  if(start==end)
        return del(start,end);
    end=end->prev;
    delete end->nxt;
    end->nxt=NULL;
}
void del_specific(node * &start, node * &end)
{   if(start==NULL)
       return;
    int n;
    cout<<" Enter the Specific Value you want to delete :";
    cin>>n;
    if(n==start->val)
         return del_start(start,end);
    if(n==end->val)
        return del_end(start,end);
    node *temp=start;
    while(n!=temp->val)
    {
        temp=temp->nxt;
        if(temp==NULL)
          {cout<<"No Element found to be deleted";return;}          
    }
    temp->nxt->prev=temp->prev;
    temp->prev->nxt=temp->nxt;
    delete temp;

}
int main()
{
    int n;
    node *start=NULL;
    node *end=NULL;
    cout<<"Press 0 to insert at start,1 to insert at specific position,2 to insert at end,3 to traverse & 4 to delete:";
    cin>>n;
    while(n!=-1)
    { 
        if(n==0)
          insert_start(start,end);
        if(n==1)
            insert_specific(start,end);
        if(n==2)
          insert_end(start,end);
        if(n==3)
          traverse(start);
          
        if(n==4 ) 
        {  
            cout<<"\nPress 5 to delete first element,6 to delete last element,7 to delete any specific element:";
            cin>>n;
            if(n==5)
               del_start(start,end);
            if(n==6)
               del_end(start,end);
            if(n==7)
               del_specific(start,end);
        }   
      cout<<"Press 0 to insert at start,1 to insert at specific position,2 to insert at end,3 to traverse & 4 to delete:";
      cin>>n;   
    }
}