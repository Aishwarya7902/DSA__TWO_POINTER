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
  

/*
two pointer based approach
tc:o(n)
sc:o(1)
pseudo code
1) Initialize two variables l and r to find the candidate 
   elements in the sorted array.
       (a) l = 0
       (b) r = n - 1
2) Initialize : result = 0
2) Loop while l < r.

    // If current left and current
    // right have sum smaller than x,
    // the all elements from l+1 to r
    // form a pair with current
    (a) If (arr[l] + arr[r] < x)  
          result = result + (r - l)  
          l++;    
   
    (b) Else
            r--;
       
3) Return result
*/

int countPair(vector<int>&nums,int x){
    int cnt=0;
    int n=nums.size();
    int l=0,r=n-1;
    while(l<r){
    // If current left and current
    // right have sum smaller than x,
    // the all elements from l+1 to r
    // form a pair with current
        if(nums[l]+nums[r]<x){
            cnt+=r-l; //r-(l+1) +1 since 0 based indexing
            l++;
        }
        else{
            r--;
        }
        
    }
    return cnt;
}

  
