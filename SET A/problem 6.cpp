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

/*
OPTIMISATION
PSEUDO CODE:
TC:O(N^2)
SC:O(1)
PSEUDO CODE:
sort in descending order
1.run an outer loop
2.take high=i+1
3.low=n-1
4.while(high<low){
	    if(arr[high]+arr[low]==arr[i])cnt++;
	    if(arr[high]+arr[low]<arr[i])low--;
	            else
	             high++;
	        }
	    }
	    return cnt
*/

class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{   int cnt=0;
	    // Your code goes here
	    sort(arr,arr+n,greater<int>()); //sort in descending order
	    for(int i=0;i<n;i++){
	        int high=i+1;
	        int low=n-1;
	        while(high<low){
	            if(arr[high]+arr[low]==arr[i])cnt++;
	            if(arr[high]+arr[low]<arr[i])low--;
	            else
	             high++;
	        }
	    }
	    return cnt;
	}
};
