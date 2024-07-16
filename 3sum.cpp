//solving 3 sum problem using 2 pointer approach in O(n2);
#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

 vector<vector<int> > threeSum(vector<int>& nums) {
    int n =nums.size();
    sort(nums.begin(),nums.end());  
    vector<int> tmp;
    if(n==3 and (nums[0]+nums[1]+nums[2]==0))
    {  tmp.push_back(nums[0]);tmp.push_back(nums[1]);tmp.push_back(nums[2]);
       vector<vector<int> > ans;
       ans.push_back(tmp);
       return ans;
    }
    set<vector<int> > set1;
    for(int i =0;i<n-3;i++)
    { int j = i+1,k=n-1;
    while(j<k){
      if(nums[i]+nums[j]+nums[k]==0)
      { tmp.push_back(nums[i]);
        tmp.push_back(nums[j]);
        tmp.push_back(nums[k]); set1.insert(tmp); tmp.clear();k--;j++; }
     else if(nums[i]+nums[j]+nums[k]>0)
       k--;
       else
       j++;
    } } 
    vector<vector<int> > ans(set1.begin(),set1.end());
    return ans;
} 
int main()
{
    int arr[]={-1,0,1,2,-1,-4};
    vector<int> nums(arr,arr+6);
    vector<vector<int> > ans= threeSum(nums);
    for(int i =0;i<ans.size();i++)
    {
      for(int j =0;j<ans[i].size();j++)
          cout<<ans[i][j]<<" ";
      cout<<endl;
    }
}
