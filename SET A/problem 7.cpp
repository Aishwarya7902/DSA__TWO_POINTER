PROBLEM:https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO:

/*
NAIVE SOLUTION
TC:O(N^4)
SC:O(1)
PSEUDO CODE
1.run four for loops and check for given condition
*/


/*
OPTIMISATION
TC:O(N^3)
SC:O(1)
PSEUDO CODE:
1.Sort
2.run two for loops i,j
3.now our newtarget is k-(arr[i]+arr[j])
4.low=j+1,high=n-1
5.while(low<high)
6.int twoSum=arr[low]+arr[high];
                    if(twoSum<target)
                     low++;
                    else if(twoSum>target)
                     high--;
                   else{
                       vector<int>curr(4,0);
                       curr[0]=arr[i];
                       curr[1]=arr[j];
                       curr[2]=arr[low];
                       curr[3]=arr[high];
                       ans.push_back(curr);
                       while(low<high && arr[low]==curr[2])low++;
                       while(low<high && arr[high]==curr[3])high--;
                       
                   }
7.return ans
*/

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
       vector<vector<int>>ans;
       for(int i=0;i<arr.size();i++){
           for(int j=i+1;j<arr.size();j++){
               int target=k-(arr[i]+arr[j]);
               int low=j+1,high=arr.size()-1;
               while(low<high){
                   int twoSum=arr[low]+arr[high];
                    if(twoSum<target)
                     low++;
                    else if(twoSum>target)
                     high--;
                   else{
                       vector<int>curr(4,0);
                       curr[0]=arr[i];
                       curr[1]=arr[j];
                       curr[2]=arr[low];
                       curr[3]=arr[high];
                       ans.push_back(curr);
                       while(low<high && arr[low]==curr[2])low++;
                       while(low<high && arr[high]==curr[3])high--;
                       
                   }
               }
               while(j<arr.size() && arr[j+1]==arr[j])j++;
           }
           while(i<arr.size() && arr[i+1]==arr[i])i++;
       }
       return ans;
    }
};
