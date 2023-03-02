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
start=0,end=0
int count=0,sum=nums[0];
int n=nums.size();

ALGORITHM
1.we will add an element to our window if at this moment sum<k
2.end++
3.now update both count and sum
4.count of element will be equal to subarray length i.e end-start
but first check if end>=start...otherwise count will become negative

5.add arr[end] to sum.........but first check for edge case.....that is to say if end<n ....then only add to sum

6.if sum becomes greater than or equal to  k then remove arr[start] from sum and deacrease window size by moving start++

7.do all above steps till end<n

8.return cnt


*/
#include <bits/stdc++.h>
using namespace std;
int countSubarraySumLessThanK(vector<int>&arr,int n,int k){
    int start=0,end=0;
    int cnt=0,sum=arr[0];
    while(end<n){
        //add element to our window till sum<k
        if(sum<k){
            end++;
            //update sum and count
            if(end>=start)
             cnt+=end-start;
            if(end<n)
             sum+=arr[end];
        }
        //if sum>=k ...remove arr[start] from sum and decrease window 
        //size by moving start by 1
        else{
            sum-=arr[start];
            start++;
        }
    }
    return cnt;
}

int main() {
    vector<int>arr({ 1, 11, 2, 3, 15 });
	cout<<countSubarraySumLessThanK(arr,5,10);
	return 0;
}

/*METHOD 3:
VIDEO LINK(FOR BETTER EXPLANATION):https://www.youtube.com/watch?v=Hts2wpzhuwQ&t=156s
*/
#include <bits/stdc++.h>
using namespace std;
int countSubarraySumLessThanK(vector<int>&arr,int n,int k){
    int left=0;
    int cnt=0,sum=0;
    for(int right=0;right<n;right++){
        sum+=arr[right];
        while(sum>=k){
            sum-=arr[left];
            left++;
        }
        cnt+=right-left+1;
    }
    return cnt;
}

int main() {
    vector<int>arr({ 1, 11, 2, 3, 15 });
	cout<<countSubarraySumLessThanK(arr,5,10);
	return 0;
}
