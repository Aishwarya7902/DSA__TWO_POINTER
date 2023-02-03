PROBLEM:https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

/*
TC:O(N)
SC:O(1)
*/

#include <bits/stdc++.h>
using namespace std;
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

int main() {
//     string s="abc";
// 	cout<<ExactKChar(s,2);
string s="abcbaa";
	cout<<AtmostKChar(s,3)-AtmostKChar(s,2);
	return 0;
}
