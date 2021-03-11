Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"

Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"

 

Constraints:

    1 <= s.length <= 1000
    1 <= dictionary.length <= 1000
    1 <= dictionary[i].length <= 1000
    s and dictionary[i] consist of lowercase English letters.


***********************************
class Solution {
public:
    // time=0(nx), n is length of dict and x is average length of strings in dict
    bool issubsequence(string pattern,string s)
    {
        int i=0,j=0;
        while(i<pattern.length() && j<s.length())
        {
            if(pattern[i]==s[j])
            {
                i++;
                j++;
            }
            else{
                j++;  // increment only original
            }
        }
        return i==pattern.length(); // if whole pattern string is covered
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string max_str="";
        for(string str:dictionary)
        {
            if(issubsequence(str,s)) // check if str is subsequence of s using this function
            {
                if(str.length()>max_str.length() || (str.length()==max_str.length() && str<max_str))
                {
                    max_str=str;
                }
            }
        }
        return max_str;
    }
};
