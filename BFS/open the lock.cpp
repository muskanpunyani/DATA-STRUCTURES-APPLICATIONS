You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1

 

Constraints:

    1 <= deadends.length <= 500
    deadends[i].length == 4
    target.length == 4
    target will not be in the list deadends.
    target and deadends[i] consist of digits only.



***********************************
class Solution {
public:
    /*
    we need to have shortest path from "0000" to "target" without any deadlocks in the path
    edges from 0 to 1,1 to 0 and vice versa for everything
    last case: 9 to 0 and 0 to 9
    
    // thus starting position is "0000" and then apply bfs for all possibilities
    // we will make deadends as visited to skip them
    */
   /**
* Time Complexity: where N is the length of lock (4 in our case):
*
* O(N) for enumerating neighbors,
* O(digits^N) (10^4 in this case neighbors for each node)
* O(D) for initializing deadends set
* So time complexity is O(N*digits^N + D)
*
* Space complexity: O(digits^N + D) or the queue and the set dead
*/
   
    vector<string> all_possibilities(string temp)
    {
        vector<string> res;
        for(int i=0;i<temp.size();i++)
        {
            char c=temp[i];
            temp[i]=(c=='9')?'0':(((c-'0')+1)+'0'); // 1 ahead
            res.push_back(temp);
            temp[i]=(c=='0')?'9':(((c-'0')-1)+'0'); // 1 backward
            res.push_back(temp);
            temp[i]=c;
            
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(),deadends.end());
        if(visited.find(target)!=visited.end())
        {
            return -1;
        }
        queue<string> q;
        q.push("0000");
        int level=0;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                string temp=q.front();
                q.pop();
                if(visited.find(temp)!=visited.end())
                {
                    continue;
                }
                visited.insert(temp); // add temp to visited so that we will nit take reppeated elements
                if(temp==target)
                    return level;
                vector<string> v=all_possibilities(temp); // push all the possibilities from this string to queue
                for(string s1:v)
                {
                    if(visited.find(s1)==visited.end()) // if not visited,add
                    {
                        q.push(s1);
                    }
                }
                
            }
            level++;
        }
        return -1;
    }
};
