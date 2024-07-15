//Linked list implementation of deque
#include<iostream>
using namespace std;
class node
{   public:
    node *prev;
    int val;
    node *nxt;
    node(int n)
    {
        prev=NULL;
        val=n;
        nxt=NULL;
    }
    ~node()
    {
        cout<<val<<" removed \n";
    }
};
class deque
{
  node *front;
  node *rear;
  int siz;
  int cur;
  public:
  deque(int k)
  { front=NULL;
    rear=NULL;
    siz=k;
    cur=-1;
  }
  bool push_front(int n)
  { if(cur==siz-1)
    { cout<<"DEQUE OVERLOW \n";return false;}
    node * current= new node(n);
    if(front==NULL)
        rear=current;
    else
    { front->prev=current;
        current->nxt=front; }
    front=current;
    cur++;
    return true;
  }
  bool push_back(int n)
  { if(cur==siz-1) 
    { cout<<"DEQUE OVERLOW \n";return false;}
    node *current = new node(n);
    if(rear==NULL)
       front=current;
    else
    { rear->nxt=current;
      current->prev=rear;
    }
    rear=current;
    cur ++;
    return true;
  }
  bool pop_front()
  { if(front==NULL)
    {cout<<"deque underflow\n";return false;}
    node *n=front;
    if(front==rear)
        front=rear=NULL;
    front=front->nxt;
    delete n;
    cur--;
    return true;
  }
  bool pop_back()
  {  if(rear==NULL)
    {cout<<"deque underflow\n";return false;}
    node *n=rear;
    if(front==rear)
        front=rear=NULL;
    rear= rear->prev;
    delete n;
    cur--;
    return true;
  }
  int size()
  {return cur+1;}
  void traverse()
  { if(front==NULL)
      return;
    node *n=front;
    while(front!=NULL)
    {
        cout<<front->val;
        if(front->nxt!=NULL)
            cout<<" ";
        front=front->nxt;
    }
    front=n;
  }
  int get_front()
  {if(front!=NULL)
      return front->val;
   return INT_MAX;
   }
int get_rear()
  {if(rear!=NULL)
      return rear->val;
   
   return INT_MAX;}

};
int main()
{
    deque deq(10);
    deq.push_front(30);
    deq.push_front(20);
    deq.push_front(10);
    deq.push_front(5);    
    deq.push_back(40);
    deq.push_back(50);
    deq.push_back(60);
    deq.traverse();
    cout<<endl;
    cout<<deq.get_front()<<endl;
    cout<<deq.get_rear()<<endl;
    cout<<deq.size();
}