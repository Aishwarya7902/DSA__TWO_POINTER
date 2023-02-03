problem: https://www.lintcode.com/problem/386/

int AtmostKChar(string s,int k){
   int n=s.size();
   int begin=0,end=0;
   int cnt=0;
   unordered_map<char,int>mp;
   while(end<n){
       mp[s[end]]++;
       end++;
     
       while(mp.size()>k)
       {
           mp[s[begin]]--;
           if(mp[s[begin]]==0)
            mp.erase(s[begin]);
          
            begin++;
       }
       cnt+=end-begin+1;
   }
   return cnt;
}




 
