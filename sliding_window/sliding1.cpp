//Maximum SUM subarray of size K(sliding window basic)
#include<iostream>
using namespace std;
int main()
{
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"size of subarray :";
    cin>>k;

    int currsum=0;int maxsum;
    for(int i =0;i<k;i++)
        currsum+=arr[i];
     maxsum=currsum;
    int i =1,j=k,idx=0;
    
    while(j<n)
    {   
        currsum = currsum+arr[j]-arr[i-1];
        if(currsum>maxsum)
        {idx=i;maxsum=currsum;}
    j++,i++;
    }
cout<<"SUBARRAY from index :"<<idx+1<<"  to "<<idx+k<<"  value : "<<maxsum;
}