//singly circular linked list
#include<iostream>
using namespace std;
class node
{
   public:
   int val;
   node *nxt;
   node(int a)
   {val=a; nxt=NULL;}
   ~node()
   {
      cout<<val<<" has been deleted";
   }
};
void insert_start(node * &start,node * &end)
{  int n;
   cout<<"Enter the value to be inserted at starting:";
   cin>>n;
   node * current= new node(n);
   if(start==NULL)
      end=current;
    else
     current->nxt=start;
    start=current;
    end->nxt=start;
   }
void insert_end(node * &start,node * &end)
{ 
   int n;
   cout<<"Enter the value to be inserted at end:";
   cin>>n;
   node * current=new node(n);
   if(end==NULL)
      start=current;
   else
      end->nxt=current;
    end=current;
    end->nxt=start;

   }
void insert_specific(node * &start, node* & end)
{
   int n;
   cout<<"Enter the Position at which you want to insert:";
   cin>>n;
   if(start==NULL && n>0) // no values
     {cout<<"Values upto "<<n<<" position does not exist"<<endl; return;}

   if(start==NULL && n==0) //fresh insert value
     return insert_start(start,end);
   if(start->nxt==start && n==1) //insert at first index after zeroth;
      return insert_end(start,end);
   if(start!=NULL && n==0) // insert at 0th index before 0th value;
      return insert_start(start,end);
   node *current=start;
   for(int i=0;i<n-1;i++)
   { if (current== end)
       {cout<<"Values upto "<<n<<" position does not exist "<<endl; return;}
      current=current->nxt;
   }
   if(current->nxt==NULL)
      return insert_end(start,end); //insert at end in long linked list
   int j;
   cout<<"Enter the value to be inserted at "<<n<< " Index:";
   cin>>j;
   node * fresh= new node(j);
   fresh->nxt=current->nxt;
   current->nxt=fresh;   
}
void traverse(node *start)
{
   if(start==NULL)
   {cout<<"NO values to traverse "<<endl;return;}
   cout<<start->val<<" "<<start->nxt;
   if(start==start->nxt)
        {cout<<endl; return;}
   node * current= start->nxt;
   while(current!=start)
   {  cout<<"->";
      cout<<current->val<<" "<<current->nxt;
      current=current->nxt;
   }
   cout<<endl;
}
int main()
{
   node * start=NULL;
   node * end=NULL;
   int n;
   cout<<"Press 0 to insert at start,1 to insert at specific pos,2 to insert at end,3 to traverse, 4 to delete:";
   cin>>n;
   while(n!=-1)
   {  if(n==0)
         insert_start(start,end);
      else if(n==1)
         insert_specific(start,end);
      else if(n==2)
         insert_end(start,end);
      else if(n==3)
         traverse(start);
   cout<<"Press 0 to insert at start,1 to insert at specific pos,2 to insert at end,3 to traverse, 4 to delete:";
   cin>>n;
   }
}