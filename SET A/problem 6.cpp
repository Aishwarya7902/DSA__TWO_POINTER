PROBLEM:https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO:

/*
NAIVE SOLUTION:
TC:O(N^3)
SC:O(1)
PSEUDO CODE
1.run three for loops and check for given conditions
*/
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{   int cnt=0;
	    // Your code goes here
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            for(int k=j+1;k<n;k++){
	                if(arr[i]+arr[j]==arr[k] ||arr[i]+arr[k]==arr[j] ||arr[j]+arr[k]==arr[i] )cnt++;
	            }
	        }
	    }
	    return cnt;
	}
};
