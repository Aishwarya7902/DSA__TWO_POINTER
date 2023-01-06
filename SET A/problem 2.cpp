PROBLEM:https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1
VIDEO:

/*
BRUTE FORCE:
TC:O(N^2)
SC:O(1)
PSEUDO CODE
1.maintain a diff variable which will tell us closet difference till now
2.run two for loops
3.take a ans vector of size two to store ans
4.if(abs(x-(arr[i]+brr[j]))<diff){ //if the two pairs sum up and difference is closer than previous difference ,
update diff and store current pairs in ans since they might become ans in future
 
     ans[0]=arr[i];            
     ans[1]=brr[j];
     diff=abs(x-(arr[i]+brr[j]));
  }
*/


class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int>ans(2,0);
        int diff=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(abs(x-(arr[i]+brr[j]))<diff){
                    ans[0]=arr[i];            
                    ans[1]=brr[j];
                    diff=abs(x-(arr[i]+brr[j]));
                }
            }
        }
        return ans;
    }
};
