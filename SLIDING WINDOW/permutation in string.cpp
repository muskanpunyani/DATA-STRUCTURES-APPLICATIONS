Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

 

Constraints:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000]


class Solution {
public:
    /*
    we will create a map and check every substring of size pattern,and if we got whole substring in that specific size of original string sing sliding window,then found
    
    */
    // time=0(n)
    // space=0(k),where k is length of s1
    bool checkInclusion(string s1, string s2) {
        int patternlength=s1.length();
        map<char,int> m;   // map foor pattern
        for(int i=0;i<patternlength;i++)
        {
            m[s1[i]]++;
        }
        int start=0;
        int match=0;
        for(int end=0;end<s2.length();end++)
        {
           char right=s2[end];
           if(m.find(right)!=m.end()) // present
           {
               m[right]--;
               if(m[right]==0) // if 0 freq,i.e total match
               {
                   match++;
               }
           }
          
           if(end-start+1 > patternlength) // reduce window size
           {
               char left=s2[start];
               start++;
               if(m.find(left)!=m.end())
               {
                   if(m[left]==0)  // taken into consideration,whole was covered
                   {
                       match--;
                   }
                   m[left]++;
               }
           }
             if(match==m.size()) // if same map size id found
           {
               return true;
           }
        
        }
        return false;
    }
};
