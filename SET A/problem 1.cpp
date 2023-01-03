PROBLEM:https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
VIDEO: (striver bhaiya) https://youtu.be/Fm_p9lJ4Z_8

/*
NAIVE SOLUTION
🟦USING A SET
PSEUDO CODE
1.insert elements of nums in set,set will store unique elements
2.now place back elements of the set back into array starting from position 0
3.return size of set since this will be the no of distict elements in array
🟦 TC: O(nlogn) + O(n) // n for traversing in array and logn for inserting in set + n to take elements out of the set and place them in the array(in worst case
all the elements of the array are unique)
🟦 SC: O(n) //(in worst case all the elements of the array are unique so u will have to store them in the set)
*/
#include<set>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        int i=0;
        for(auto it:s){
            nums[i]=it;
            i++;
        }
        return s.size();
    }

};

/*
OPTIMISATION
USING TWO POINTER
TC:O(N)
SC:O(1)
PSEUDO CODE
1.set i,j
2.now move j till u find something different from ith position i.e j++
3.now since we have to do inplace
nums[i+1]=nums[j]
i++;
j++
4.when we  move out of loop
return i+1 ,it will be size of distinct elements in array
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0,j=0;
       while(j<nums.size()){
           if(nums[i]==nums[j])j++;
           else{
               nums[i+1]=nums[j];
               i++;
               j++;
           }
       }
       return i+1; 
    }
};
