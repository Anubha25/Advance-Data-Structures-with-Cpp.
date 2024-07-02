#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int largest(vector<int> &height)
{      int n= height.size();
       vector<int> output1(n,0),output2(n,0);stack<int> stack1;     
       output1[n-1]=n;output2[0]=n;
    //next smaller element index:
       stack1.push(0);
       for(int i=1;i<n;i++)
       { int z= stack1.top();
        while(!stack1.empty() && height[z]>height[i])
           { output1[z]= i;
             stack1.pop(); 
             if(!stack1.empty())
             z= stack1.top();
           }
           stack1.push(i);
       }
       while(!stack1.empty())
       { output1[stack1.top()]=n; stack1.pop(); }
    
    for(int i=0;i<n/2;i++)
      { int temp=height[i];
        height[i]=height[n-i-1];
        height[n-i-1]=temp;
      }
    //previous greater element(by reveresing the array and vector and finding next smaller element)
    stack1.push(0);
       for(int i=1;i<n;i++)
       { int z= stack1.top();
        while(!stack1.empty() && height[z]>height[i])
           { output2[z]= i;
             stack1.pop(); 
             if(!stack1.empty())
             z= stack1.top();
           }
           stack1.push(i);
       }
       while(!stack1.empty())
       { output2[stack1.top()]=n; stack1.pop(); }
      for(int i=0;i<n;i++)
        cout<<output1[i]<<" ";
      cout<<endl;
      for(int i=0;i<n;i++)
        cout<<output2[i]<<" ";
        
        
}



int main()
{   int arr[]={2,1,5,6,2,3,0,2,1,5,6,2,3};
    vector<int> height(arr,arr+13); // the orignal way wasmnnot working on vscode
    largest(height);
}