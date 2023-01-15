PROBLEM: https://www.geeksforgeeks.org/count-pairs-array-whose-sum-less-x/
Given a sorted integer array and number x, the task is to count pairs in array whose sum is less than x.
  
/*
naive solution
1.run two for loops and find every possible pair....and if sum<x cnt++
tc: o(n^2)
sc:O(1)
*/
  
#include <bits/stdc++.h>
using namespace std;
int countPair(vector<int>&nums,int x){
    int cnt=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]<x)cnt++;
        }
    }
    return cnt;
}

int main() {
    vector<int>nums({1, 2, 3, 4, 5, 6, 7, 8});
	cout<<countPair(nums,7);
	return 0;
}
  
  
  
