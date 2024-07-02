#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> next_greater(vector<int> &arr)
{ int s=arr.size();
   vector<int> output(s,-1);
   stack<int> stack1;
   stack1.push(0);
   for(int i=1;i<s;i++)
    { if(!stack1.empty() and arr[stack1.top()]>arr[i])
        stack1.push(i);
      else 
       {   while(!stack1.empty() && arr[stack1.top()]<arr[i])
        { output[stack1.top()]=arr[i];
           stack1.pop(); 
        }
        stack1.push(i); 
       }
    }
  return output;
}
int main()
{   int a[]={4,6,3,1,0,9,5,6,7,3,2};
    vector<int> arr(a,a+11); // the orignal way wasmnnot working on vscode
    for(int ele:arr)
       cout<<ele<<" ";
    cout<<endl;
    vector<int> n= next_greater(arr);
    for(int ele:n)
      cout<<ele<<" ";
    
}