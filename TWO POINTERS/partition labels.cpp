A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

 

Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.

 

********************
class Solution {
public:
    /*
    we are creatin a map where we are storing the max freq of each character
    and then we traverse the string and find the max index,and put the ranges accordingly
    */
    vector<int> partitionLabels(string S) {
        // o(n) time
        // o(1) space
        vector<int> ans;
        vector<int> storage(26,0);
        for(int i=0;i<S.length();i++) // store the max index of every char
        {
            storage[S[i]-'a']=i;
        }
        int max_index=-1;
        int start_index=0;
        for(int i=0;i<S.length();i++)
        {
            max_index=max(max_index,storage[S[i]-'a']);
            if(max_index==i)  // i.e the maximum index is at this point only,we can partition
            {
                ans.push_back(max_index-start_index+1);
                // if we want string S.substr(start_index,max_index-start_index+1);
                // substr(start index,length);
                // starting from start index till this length;
                start_index=i+1;  // starting new string partiton
            }
        }
        return ans;
        
    }
};
