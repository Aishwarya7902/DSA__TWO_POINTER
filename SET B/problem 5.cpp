PROBLEM:https://leetcode.com/problems/subarray-product-less-than-k/description/
VIDEO:

/*
NAIVE SOL
use two for loops
tc:o(n^2)
sc:o(1)
*/

/*
two pointer
tc:o(n)
sc:o(1)
start=0,end=0
int count=0,prod=nums[0];
int n=nums.size();
ALGORITHM
1.we will multiply an element to our window if at this moment prod<k
2.end++
3.now update both count and prod
4.count of element will be equal to subarray length i.e end-start
but first check if end>=start...otherwise count will become negative
5.multiply arr[end] to sum.........but first check for edge case.....that is to say if end<n ....then only multiply to prod
6.if prod becomes greater than or equal to  k then remove arr[start] from prod by division  and deacrease window size by moving start++
7.do all above steps till end<n
8.return cnt

*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0,end=0;
        int cnt=0,prod=nums[0];
        while(end<n && start<n){
            if(prod<k){
                end++;
                //update count and prod
                if(end>=start)
                 cnt+=end-start;
                if(end<n)
                 prod*=nums[end];
            }
            else{
                prod/=nums[start];
                start++;
            }
        }
        return cnt;
    }
};
