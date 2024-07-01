
#include<iostream>
using namespace std;
class stacks
{
 int *arr;
 int capacity;
 int top;
 int *mint;
public:
stacks(int n)
{
    arr= new int[n]; // we create array of size n and assign address of array[0] to arr;
    capacity=n;
    top=-1;
    mint= new int[n];
}
void push() 
{
    if(top==capacity-1)
        {cout<<"Stack Overflow"<<endl; return;}
    cout<<"enter the value to be inserted :";
    cin>>arr[++top];
}
int pop()
{ if(top==-1)
    {cout<<"No elements to Pop/stack underflow"<<endl;return INT_MIN;}
    return arr[top--];
}

int top_element()
{
    if(top==-1)
       { cout<<"stack is empty"<<endl; return INT_MIN;}
    return arr[top];
}
int size(){
 return top+1; }

bool isfull()
{  return top==capacity-1;}

bool isempty()
{   return top==-1;}

void traverse()
{ if(top==-1)
  { cout<<"No values to traverse"<<endl; return ;}
  cout<<"STACK \n";
for(int i=top;i>=0;i--)
      cout<<arr[i]<<endl;
}
};

int main()
{ 
stacks stack1(10);
int n;
   cout<<"Press 0 to Push Stack,1 to Pop stack,2 to get stack size,3 to traverse Stack,4 to get top element, \n 5 to check full stack,6 to check empty stack:";
   cin>>n;
   while(n!=-1)
   {  if(n==0)
        stack1.push();
      else if(n==1)
        cout<<"Element popped :"<<stack1.pop()<<endl;
      else if(n==2)
        cout<<"stack size :"<<stack1.size()<<endl; 
      else if(n==3)
         stack1.traverse();
      else if(n==4)
        cout<<"Top elememt:"<<stack1.top_element()<<endl;
      else if(n==5)
       { if(stack1.isfull())
           cout<<"STACK IS FULL !"<<endl;
        else 
           cout<<"STACK IS NOT FULL"<<endl; }
      else if(n==6)
       { if(stack1.isempty())
            cout<<"stack is Empty!"<<endl;
        else 
          cout<<"stack is not empty"<<endl; }
     cout<<"Press 0 to Push Stack,1 to Pop stack,2 to get stack size,3 to traverse Stack,4 to get top element,\n 5 to check full stack,6 to check empty stack:";
     cin>>n;
}   }