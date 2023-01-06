PROBLEM:https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO:

/*
APPROACH 1:
tc:o(n^3)
sc:o(1)
pseudo code
1.run three loops and check if all sum to zero
*/


/*
optimisation
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

pseudo code:
1.sort
2.run an outer loop
3.l=i+1,j=n-1
4.while(l<r)
if(arr[l]+arr[r]==-num)return true;
              if(arr[l]+arr[r]<-num)l++;
              else
              r--;
 5.if none of the above returns true ,return a false             
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {    sort(arr,arr+n);
        //Your code here
      for(int i=0;i<n;i++){
          int num=arr[i];
          int l=i+1;
          int r=n-1;
          while(l<r){
              if(arr[l]+arr[r]==-num)return true;
              if(arr[l]+arr[r]<-num)l++;
              else
              r--;
          }
      }
      return false;
    }
};
