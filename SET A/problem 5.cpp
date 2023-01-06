PROBLEM:https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
VIDEO:

/*
tc:o(n^3)
sc:o(1)
BRUTE FORCE:
PSEUDO CODE:
1.run three for loops
2.if condition satiesfies return true
3.else return false
*/
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(A[i]+A[j]+A[k]==X)return true;
                }
            }
        }
        return false;
    }

};

/*
OPTIMISATION
TC:O(N^2)
SC:O(1)
PSEUDO CODE:
1.run an outer loop
2.low=i+1,high=n-1
3.int required=X-A[i];
4.while(low<high){
                if(A[low]+A[high]==required)return true;
                if(A[low]+A[high]<required)low++;
                else
                high--;
            }
5.else return false;
*/
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n;i++){
            int required=X-A[i];
            int low=i+1,high=n-1;
            while(low<high){
                if(A[low]+A[high]==required)return true;
                if(A[low]+A[high]<required)low++;
                else
                high--;
            }
        }
        return false;
    }

};
