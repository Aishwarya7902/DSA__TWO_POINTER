PROBLEM:https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

/*
TC:O(N)
SC:O(1)
*/

class Solution
{
  private:
 long long int solve(string &s, int k) {
      if(s.size()==0)return 0;
      map<char,int>mp;
       long long int cnt=0;
      int left=0;
      for(int i=0;i<s.size();i++){
          mp[s[i]]++;
          while(mp.size()>k){
              mp[s[left]]--;
              if(mp[s[left]]==0){
                  mp.erase(s[left]);
              }
              left++;
              
          }
          cnt+=i-left+1;
      }
    	//code here.
    	return cnt;
    }
  public:
    
    long long int substrCount (string &s, int k) {
    	//code here.
    return solve(s,k) - solve(s,k-1);
    }
};
NOTE:GIVING TLE IN GFF (PAGAL HO GAYE HAIN YE LOG)
