Given two strings s and t, return the minimum window in s which will contain all the characters in t. 
  If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Example 2:

Input: s = "a", t = "a"
Output: "a"

 

Constraints:

    1 <= s.length, t.length <= 105
    s and t consist of English letters.

 
Follow up: Could you find an algorithm that runs in O(n) time?



class Solution {
public:
    /*
    class Solution {
public:
    string minWindow(string s, string t) {
        
        
        int l = 0;
        int r = 0;
        int min_val = INT_MAX;
        int len_s = s.size();
        
        map<char,int> h;
        
        int counter = t.size();
        
        int start = 0;
        
        
        for(int i = 0; i < t.size(); i++)
        {
            h[t[i]]++;
        }
        
        while(r < len_s)
        {
            // Expand Window: Move the right Pointer forward to expand the Sliding Window
            if(h[s[r]] > 0)
            {
                counter--;
                
            }
            h[s[r]]--;
            r++;
            
            // Contract Window: Move the left Pointer ahead to contract the Window and see till when the
            // window can be contracted and still it will find all the characters of t
            // in the window.
            while(counter == 0)
            {
                
                if(min_val > r - l)
                {
                    min_val = r - l;
                    start = l;
                }
                  
                if(h[s[l]] == 0)
                {
                    counter++;
                
                }
                h[s[l]]++;
                l++;
               
                
            }
            
          
            
        }
        
        if(min_val == INT_MAX)
            return "";
        else
            return s.substr(start,min_val);
       
    }
};
    */
    string minWindow(string s, string t) {
        map<char,int> pattern; // map for t
        for(int i=0;i<t.length();i++)
        {
            pattern[t[i]]++;
        }
        int l=0,r=0;
        int start=0;
        int size_s=s.length();
        int size_t=t.length();
        int min_val=INT_MAX;
        
        while(r<size_s)
        {
            if(pattern[s[r]]>0)
            {
                size_t--;
               
            }
            pattern[s[r]]--; // if doesnt exist it will become -ve
            r++; // move right
            while(size_t==0) //i.e all char of t are covered
            {
                if(min_val > (r-l))
                {
                    min_val=r-l;
                    start=l;
                }
                if(pattern[s[l]]==0) // it means this char exist in t
                {
                    size_t++;   
                }
                pattern[s[l]]++;
                l++;
            }
        }
        if(min_val==INT_MAX)
            return "";
        return s.substr(start,min_val);
    }
};
