//QUEUE WITH ARRAY
#include<iostream>
using namespace std;
class queue
{
    int *q;
    int front;
    int rear;
    int currentsize;
    int size;
    public:
    queue(int n)
    {
      q= new int[n];
      front=rear=-1;
      currentsize=-1;
      size=n;
    }
    void enqueue(int a)
    { if(currentsize==size-1)
        {cout<<"queue Overflow \n"<<front;return;}
    
    if(front==-1)
    {  front=rear=0;
       q[front]=a;
    }
    else
    {
        rear++;
        q[rear]=a;
    }
    currentsize++;}

    void dequeue()
    { if(front==-1)
       {cout<<"queue underflow \n";return;}
      if(front==rear)
      { cout<<q[front]<<" removed \n";
        front=rear=currentsize=-1;}
    cout<<q[front]<<" removed \n";
     front++;
    }
    void traverse()
    { 
        if(front==-1)
        {cout<<"no values to traverse \n ";return;}
        if(front==rear)
        {cout<<q[front];return;}
        for(int i=front;i<=rear;i++)
          cout<<q[i]<<"->";
        cout<<endl;

    }
    int getsize()
    {
        if(front==-1)
          return 0;
        if(front==rear)
          return 1;
        if(front<rear)
         return rear-front+1;
    }

};
int main()
{
queue queue1(5);
queue1.enqueue(1);
queue1.enqueue(2);
queue1.enqueue(3);
queue1.traverse();
queue1.enqueue(4);
queue1.enqueue(5);
queue1.traverse();
queue1.dequeue();
queue1.dequeue();
queue1.dequeue();
queue1.traverse();
queue1.dequeue();
queue1.dequeue();
queue1.traverse();
cout<<endl<<queue1.getsize()<<endl;
queue1.enqueue(7);
queue1.enqueue(8);
queue1.enqueue(10);
queue1.traverse();
}

