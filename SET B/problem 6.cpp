PROBLEM:https://www.geeksforgeeks.org/count-number-of-substrings-having-at-least-k-distinct-characters/

/*
METHOD 1
1.generate all substrings
2.check if that substring has all unique characters
tc:o(n^3)
sc:o(1)
*/


/*

method 2:
sliding window and hashing
1.Initialize a HashMap
2.Stores the start and end
  indices of sliding window
3. Store the required result in ans
4.Iterate while the end
    pointer is less than n
5.Include the character at
        the end of the window
6.Increment end pointer by 
        end++;
7.Iterate until count of distinct
        // characters becomes less than K
8.Remove the character from
            // the beginning of window
9.If its frequency is 0,
            // remove it from the map
10. Update the answer
            ans += s.length() - end + 1;
            begin++;           
tc:o(n)
sc:
*/

#include <bits/stdc++.h>
using namespace std;
int CountSubstringWithAtleasKChar(string s, int k){
    int ans=0;
    int begin=0,end=0;
    int n=s.size();
    unordered_map<char,int>mp;
    while(end<n){
        char ch = s[end];
        mp[ch]++;
        end++;
        while(mp.size()>=k){
            char pre = s[begin];
            mp[pre]--;
           if( mp[pre]==0){
               mp.erase(pre);
           }
            ans+=n-end+1;
            begin++;
        }
       
    }
    return ans;
}

int main() {
     string S = "abcca";
    int K = 3;
	cout<<CountSubstringWithAtleasKChar(S,K);
	return 0;
}
