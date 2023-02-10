problem:https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans=INT_MAX;
        int start=0,end=0;
        while(end<n){
            sum+=nums[end];
            if(sum<target)end++;
            else if(sum>=target){
                while(sum>=target){
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
                }
                end++;
            }
        }
    return ans==INT_MAX ? 0 : ans;
    }
};
