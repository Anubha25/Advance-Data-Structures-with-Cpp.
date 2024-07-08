//queue with linked list 
#include<iostream>
using namespace std;
class node
{
 public:
    int val;
    node *nxt;
    node(int n)
    { val=n;
        nxt=NULL;
    }
    ~node()
    {
        cout<<val<<" deleted \n";
    }

};
class queue
{
    node *front;
    node *rear;
    int currentsize;
    int size;
    public:
    queue(int n)
    {
        size=n;
        front=NULL;
        rear=NULL;
        currentsize=-1;
    }
    void enqueue(int a)
    {  if(currentsize==size-1)
         {cout<<"QUEUE OVERFLOW \n ";return; }
       node *current= new node(a);
       if(front!=NULL)
         rear->nxt=current;
        else
           front=current;
        rear=current;
        currentsize++;
    }
    void dequeue()
    { if(front==NULL)
       {cout<<"Queue Underflow\n ";return;}
      if(front==rear)
        { delete front;
         front=rear=NULL; currentsize=-1;return; }
      node *z= front;
      front=front->nxt;
      delete z;
      currentsize--;
       
    }
    int empty()
    { if(currentsize==-1)
         return 1;
       return 0;
    }
    int full()
    { if(currentsize==size-1)
         return 1;
      return 0;
    }  
    void traverse()
    {
        if(front==NULL)
        {cout<<"No values to traverse \n"; return;}
        if(front==rear)
        {cout<<front->val<<endl;return;}
        node *fresh=front;
        while(fresh!=NULL)
        {  cout<<fresh->val;
           if(fresh->nxt!=NULL)
               cout<<"->";
           fresh=fresh->nxt;
        }
        cout<<endl;
    }
};
int main()
{
 queue *queue1 = new queue(5);
  queue1->enqueue(1);
  queue1->enqueue(2);
  queue1->enqueue(3);
  queue1->enqueue(4);
  queue1->enqueue(5);
  queue1->traverse();
  queue1->dequeue();
  queue1->dequeue();
  queue1->dequeue();
  queue1->dequeue();
  queue1->dequeue();
  queue1->enqueue(15);
  queue1->traverse();
  queue1->dequeue();
  queue1->dequeue();
  queue1->traverse();
  cout<<queue1->empty()<<endl;
  cout<<queue1->full();
}