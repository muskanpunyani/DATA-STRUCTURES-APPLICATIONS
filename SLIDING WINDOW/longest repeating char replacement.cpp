Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.

In one operation, you can choose any character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.

 

Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

 



class Solution {
public:
    /*
    1] we will keep a map , and insert char to it with the frequency
    2] if any char is having maxx freq ,change all the in between characters to the max one and keep track of length
    3] if window size is having more diff elem than k,reduce window
    */
    // time=0(n)
    // space=0(k)
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int start=0;
        int ans=0;
        int maxcharcount=0;
        for(int end=0;end<s.length();end++)
        {
           char right=s[end];
           m[right]++;
           maxcharcount=max(maxcharcount,m[right]);
           if(end-start+1-maxcharcount > k) // window size -the character which is occurring max if greater than k reduce window size from start
           {
               char left=s[start];
               m[left]--;
               start++;
           }
            
       ans=max(ans,end-start+1);     
    
        }
        return ans;
    }
};
