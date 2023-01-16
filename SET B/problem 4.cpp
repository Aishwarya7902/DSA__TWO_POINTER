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
