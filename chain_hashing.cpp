#include<iostream>
using namespace std;

class node
{
    public:
    int val;
    node *nxt;
    node(int val)
    {this->val=val;nxt=NULL;}
    ~node()
    {cout<<val<<" removed \n";}
};
class hashing
{   public:
    vector<node *> hash;
    hashing()
    { hash.resize(10,NULL); }
    void insert(int n)
    {  int k = n%10;
        if(hash[k]==NULL)
        {  hash[k]=new node(n); return;}
        node *cur=hash[k];
        while(cur->nxt!=NULL)
         cur=cur->nxt;
        cur->nxt=new node(n);
        return;
    }
    void search(int n)
    {
      int k = n%10;
      if(hash[k]==NULL)
      { cout<<n<<" element not present \n";return;}
      node * cur=hash[k];
      while(cur!=NULL)
      {  if(cur->val==n)
        { cout<<n<<" element present \n";return;}
       cur= cur->nxt;
      }
    cout<<n<<" element not present \n";return;
    }
    void del(int n)
    {
       int k= n%10;
       if(hash[k]==NULL)
          return;
       if(hash[k]->val==n and hash[k]->nxt==NULL)
        {hash[k]=NULL; cout<<n<<" element removed! \n";return ;}
       node * cur= hash[k];
       while(cur->nxt!=NULL and k!=cur->nxt->val)
        cur=cur->nxt;
       cur->nxt=cur->nxt->nxt;
       return;
    }
};
int main()
{
    hashing h1;
    int n;
    cout<<"Press 1 to Insert, 2 to search Element , 3 to remove:";
    cin>>n;
    while(n!=0)
    { 
     if(n==1)
    { cout<<"Enter the Ele to be Inserted :";cin>>n; h1.insert(n); }
    else if(n==2)
    { cout<<"search what ?  :";cin>>n; h1.search(n); }
    else if(n==3)
    {cout<<"Enter the Ele to be deleted :";cin>>n; h1.del(n);}
    cout<<endl;
    cout<<"Press 1 to Insert, 2 to search Element , 3 to remove:";
    cin>>n;
    }
}