PROBLEM: https://leetcode.com/discuss/interview-question/915403/google-onsite-number-of-pairs-sum-greater-or-equal-target
/*
BRUTE FORCE
1.run two for loops
tc:o(n^2)
sc:o(1)
*/

/*
OPTIMISATION
TC:O(N)
SC:O(1)
*/

int countPairs(int[] arr, int target) {
    int count = 0;
    for (int lo = 0, hi = arr.length - 1; lo < hi; ) {
        if (arr[lo] + arr[hi] >= target) {
            count += hi - lo;
            hi--;
        } else  {
            lo++;
        }
    }
    return count;
}
