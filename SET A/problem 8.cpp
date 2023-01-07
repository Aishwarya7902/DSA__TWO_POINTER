PROBLEM:https://leetcode.com/problems/squares-of-a-sorted-array/description/
VIDEO: https://www.youtube.com/watch?v=XgRIr8CCCVk

/*
NAIVE SOLUTION
TC:O(nlogn)
SC:O(N) //though we can make changes in the given array also but that is not advisable
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int>ans;
       for(auto x:nums){
           int sqr=x*x;
           ans.push_back(sqr);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};


/*OPTIMISATION
PSEUDO CODE
1.since the array is in sorted order , hence the least element is in the leftmost and biggest no is in the right most
since array may contain negative elements too,it means after squaring the most negative element will become
the greatest element ,hence in the ans array it will be on the right most.

TC:O(N)
SC:O(1)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int>ans(nums.size(),0);
       int low=0,high=nums.size()-1;
       for(int i=nums.size()-1;i>=0;i--){
       if(abs(nums[low])>abs(nums[high])){
           ans[i]=nums[low]*nums[low];
           low++;
       }
       else{
          ans[i]=nums[high]*nums[high];
           high--; 
        }
       }
       return ans;
    }
};
