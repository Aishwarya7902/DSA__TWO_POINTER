PROBLEM:https://leetcode.com/problems/two-sum/description/

/*
brute force
use two for loops
*/

/*
optmisation
use hashing
*/

/*
two pointer
use a pair of vector to store number and its correponding element before sorting
tc:o(nlogn) //due to sorting
sc:o(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i].first+v[j].first==target){
                ans.push_back(v[i].second);
                ans.push_back(v[j].second);
                break;

            }
            else if(v[i].first+v[j].first>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
        
    }
};
