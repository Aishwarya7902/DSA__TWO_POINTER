PROBLEM:https://leetcode.com/problems/subarray-product-less-than-k/description/
VIDEO:

/*
NAIVE SOL
use two for loops
tc:o(n^2)
sc:o(1)
*/

/*
optimisation using  two pointer
tc:o(n)
sc:o(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0,cnt=0;
        long prod=1;
        for(int end=0;end<nums.size();end++){
            prod*=nums[end];
            while(prod>=k && start<nums.size()){
                prod/=nums[start];
                start++;
            }
            if(prod<k){
                cnt+=end-start+1;
            }
        }
        return cnt;
    }
};
