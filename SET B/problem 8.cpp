PROBLEM:https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int maxLen=-1;
      int st=0,end=0;
      unordered_map<char,int>mp;
      while(end<s.size()){
         mp[s[end]]++;
             end++;
         
       if(mp.size()==k){
             maxLen=max(maxLen,end-st);
             //end++;
         }
         else if(mp.size()>k){
             while(mp.size()>k){
                 mp[s[st]]--;
                 if(mp[s[st]]==0){
                     mp.erase(s[st]);
                 }
                 st++;
             }
             //end++;
         }
      }
      return maxLen;
    }
};
