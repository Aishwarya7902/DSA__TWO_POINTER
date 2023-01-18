PROBLEM:https://www.geeksforgeeks.org/number-subarrays-sum-less-k/

/*
NAIVE SOLUTION:
TC:O(N^2)
SC:O(1)
run two for loops and check given  condition
*/

#include <bits/stdc++.h>
using namespace std;
int subarraySumLessThanK(vector<int>&nums,int k){
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum<=k)cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int>nums({2, 5, 6});
    
    int k=10;
	cout<<subarraySumLessThanK(nums,k);
	return 0;
}


/*
two pointer
tc:o(n)
sc:o(1)
*/
#include <bits/stdc++.h>
using namespace std;
int countSubarraySumLessThanK(vector<int>&nums,int k){
    int start=0,end=0;
    int count=0,sum=nums[0];
    int n=nums.size();
    while(start<n && end<n){
        //if sum is less than k 
        //move end by one position
        //update count and sum accordingly
        if(sum<k){
            end++;
        }
        if(end>=start)
        count+=end-start;
        //for last element
        //end may become n
        if(end<n){
            sum+=nums[end];
        }
        // if sum is greater than or equal to k 
        //subtract arr[start] from sum
        //deacrease sliding window by moving start by one position
        else{
            sum-=nums[start];
            start++;
        }
        
    }
    return count;
}

int main() {
    vector<int>nums({2,5,6});
	cout<<countSubarraySumLessThanK(nums,10)<<endl;
	return 0;
}
