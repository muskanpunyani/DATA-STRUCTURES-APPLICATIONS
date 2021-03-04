Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

 

Constraints:

    1 <= s.length <= 104
    s consists of only lowercase English letters.
    1 <= k <= 105




class Solution {
public:
    // time=0(maxunique*n) where n is length of string and max unique is no of unique characters
    // space=0(26) i.e 0(1)
    // refer notes for explanation
    int getnumberofuniquechar(string s)
    {
        int map[26]={0};
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            int c=s[i]-'a';
            if(map[c]==0)
            {
                res++;
            }
            map[c]++;
        }
        return res;
    }
    int longestSubstring(string s, int k) {
        int maxunique=getnumberofuniquechar(s);
        int countmap[26]; // for counting freq of every unique char
        int ans=0;
        for(int currunique=1;currunique<=maxunique;currunique++)
        {
            memset(countmap,0,sizeof(countmap));
            int windowstart=0,windowend=0;
            int unique=0; // unique char in window
            int countatleastk=0; // no of char having freq equal or more than k
            while(windowend<s.size())
            {
                if(unique<=currunique) // expand window to right
                {
                    int index=s[windowend]-'a';
                    if(countmap[index]==0) // if char was not present initially
                    {
                        unique++;
                    }
                    countmap[index]++;
                    if(countmap[index]==k)
                    {
                        countatleastk++;
                    }
                    windowend++;
                }
                else{  // greater,shrink window from left
                    int index=s[windowstart]-'a';
                    if(countmap[index]==k)
                    {
                        countatleastk--;
                    }
                    countmap[index]--;
                    if(countmap[index]==0) // that char end
                    {
                        unique--;
                    }
                    windowstart++;
                }
                if(unique==currunique && unique==countatleastk)
                {
                    ans=max(ans,windowend-windowstart); // here it is windowend-windowstart not windowend-windowstart+1 bcz,windowend is already incremented before coming to this if block so its already +1
                }
            }
            
        }
        return ans;
    }
};
