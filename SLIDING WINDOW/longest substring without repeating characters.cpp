Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.




class Solution {
public:/*
any chracter if occurred again,change the window
*/
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int start=-1;
        vector<int> map(256,-1);  // for all char
       for(int i=0;i<n;i++)
       {
           if(map[s[i]]>start)  // initially start and map is -1,if map is not -1 it means that value has occurred before,thus repeated
           {
               start=map[s[i]];  // change index of start to index of that char,i.e we are starting a new substring from that part
           }
           map[s[i]]=i;
           maxlen=max(maxlen,i-start); // start is from -1,i.e 1 prev,thus it is i-start and not i-start+1 bcz it is already ahead
       }
        
        return maxlen;
    }
};
