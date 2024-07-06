//Open Addressing closed Hshing. Linear Probing
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    int arr[10]={};
    k=10;
    cout<<"Press 1 to insert, 2 to search :";
    cin>>n;
    while(n!=0)
    {
        if(n==1)
        { cout<<"input :";
          int p;
          cin>>p;
          for(int i=0;i<k;i++)
          {  int ind= (p+i)%k; 
            if(arr[ind]==0)
            {  arr[ind]=p;  break; } 
          }
        }
        if(n==2)
        { cout<<"search what ? :";
          int p;
          cin>>p;
          for(int i=0;i<k;i++)
          {  int ind= (p+i)%k; 
            if(arr[ind]==p)
            { cout<<"Element found at "<<ind<<endl; break;} }
        }
        cout<<"Press 1 to insert, 2 to search :";
        cin>>n;
    }
int hash[10]={-1};
for(int i=0;i<10;i++)
    cout<<hash[i]<<" ";
}