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
