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

*/

#include <bits/stdc++.h>
using namespace std;
int atleastKDistinctChars(string&s,int k){
    //i denotes start ,j denotes end,ans stores our result
    int i=0,j=0,ans=0;
    int n=s.size();
    unordered_map<char,int>mp; //stores distinc char
    while(j<n){
        //initially we will have to do some calculations on j untill condition hits and increase j
        
        
        mp[s[j]]++;
        j++;
        
        //now condition hits❤️
        
        /*here question says atleast k distinct char ...now what does it mean..???????.........it means count 
        of distinct char should be >=k.....so the condition is count of distinct char
        >=k
        */
        
        /*
        when condition hits ...do certain things before sliding the window
        1.unaffect the effect of i
        2.get an ans from our calculation till now
        3.slide the window;
        */
        
        
        while(i<=j && mp.size()>=k){
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            ans+=n-j+1; //ans <--calc..
            /*why ans+=n-j+1 because before entering inner while loop..... j will have moved one step
            now no of subarrays having atleast k distinct char will be all subarray whose start was i and end will be at j,j+1 and so 
            on...till end
            hence n-j+1 (+1 because j wale ko include karna tha na)
            */
            i++;
        }
    }
    return ans;
}

int main() {
    string s="abccd";
	cout<<atleastKDistinctChars(s,3);
	return 0;
