Given an array of integers, our goal is to find the length of the largest subarray having the sum of its elements at most ‘k’ (i.e sum <= ‘k’) where k>0.

NOTE : all elements are +ve

/*
two pointer
tc:o(n)
sc:o(1)
*/

  int sizeOfLargestSubarray(int arr[],int n,int k){
    int i=0,j=0,res=0;
    long sum=0;
    while(i<n){
        while(j<n && sum<=k){
            sum+=arr[j];
            j++;
        }
        res=max(res,j-i);
        sum-=arr[i];
        i++;
    }
    return res;

}
