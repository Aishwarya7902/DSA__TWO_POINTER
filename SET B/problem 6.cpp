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

tc:o(n)
sc: o(n)

ALGORITHM
1.begin and end represent the start and end of window
2.cnt stores our ans
3.map stores frequency of each character of our window
4.we will perform steps till end<n
5.include current char in map till size of map <k
6.move end by 1
7.if map size >=k .....then remove start char ...and calculate ans for all substrings 
  which start from begin and are in range of n
8.return cnt
*/

#include <bits/stdc++.h>
using namespace std;
int atleastKDistinctChars(string s,int k){
    int n=s.size();
    //begin and end represent the start and end of window
    //cnt stores our ans
    int begin=0,end=0;
    int cnt=0;
    //map stores frequency of each character of our window
    unordered_map<char,int>mp;
    //we will perform steps till end<n
    while(end<n){
        //include current char in map till size of map <k
        
        mp[s[end]]++;
        //move end by 1
        
        end++;
        
        //if map size >=k .....then remove start char ...and calculate ans for all substrings 
        //which start from begin and are in range of n
        
        while(mp.size()>=k){
            mp[s[begin]]--;
            if(mp[s[begin]]==0)
             mp.erase(s[begin]);
            cnt+=n-end+1;  //why this formula ...cnt+=n-end+1  ❤️feel: cnt+=last_indx-end + 1(start wale se jo substring banega uske liye +1 kiya) +1
		//coz end ko subtract kar diya jabki usko bhi add karna tha
            begin++;
        }
    }
    return cnt;
    
}

int main() {
    string s="abcca";
	cout<<atleastKDistinctChars(s,3);
	return 0;
}
