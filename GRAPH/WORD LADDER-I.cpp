Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*****************************************************************************************************************************************************


class Solution {
public:
    queue<string> q; // we will use bfs
    void word_match(string val,map<string,bool> &m)
    {
        int l=val.length();
        for(int i=0;i<l;i++)
        {
            string ans=val;
            for(int p='a';p<='z';p++)
            {
                ans[i]=p;
                if(m.find(ans)!=m.end() && m[ans]==false)
                {
                    q.push(ans);
                    m[ans]=true;
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool> m; // first we will create map which will acts as visited map as well as , it will be benificial for finding words
        
      
        for(int i=0;i<wordList.size();i++)   // storing word list in map
        {
            m[wordList[i]]=false;    // initially everything false
        }
          if(m.find(endWord)==m.end())  // if end word is not in map
        {
            return 0;
        }
        q.push(beginWord);
        int length=1;
        m[beginWord]=true;
        while(q.empty()==false)  // until queue is empty
        {
            int s=q.size();   // we go level by level
            for(int i=0;i<s;i++)
            {
                string val=q.front();
                q.pop();
                if(val==endWord)
                    return length;
                
                word_match(val,m);   // find matching word in map with 1 char different
    
            }
            length++;
        }
        return 0;
    }
   
};
