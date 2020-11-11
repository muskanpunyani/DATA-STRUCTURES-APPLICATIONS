Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period '.' refers to the current directory. Furthermore, a double period '..' moves the directory up a level.

Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names. The last directory name (if it exists) must not end with a trailing '/'. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:

Input: path = "/a/./b/../../c/"
Output: "/c"

 

Constraints:

    1 <= path.length <= 3000
    path consists of English letters, digits, period '.', slash '/' or '_'.
    path is a valid Unix path.

**********************************************************************************************************************************



class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string> s;
       
        string ans;
        
      for(int i=0;i<n;i++)
        {
             string temp;           // everytime new string for new word,temporary string
            while(path[i]=='/')     // ignore slashes
                  {
                      i++;
                  }
            while(i<n && path[i]!='/')   // create temp string 
            {
                temp.push_back(path[i]);
                i++;
            }
            if(temp=="..")                 // if string is ".." , go back to parent directory, i.e pop top
            {
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else if(temp==".")          // dont do anything
            {
                continue;
            }
            else if(temp.length()!=0){     // push the string otherwise
                s.push(temp);
            }
        }
      // if we store stack in string and reverse it,characters of string will also be reversed
        // therefore, we will reverse the stack and then store it in string
        
        stack <string> s1;
        while(s.empty()==false)
        {
            s1.push(s.top());
            s.pop();
        }
        // now string from s1
       // ans+=s1.top();
       // s1.pop();
        ans+="/";                   // ans start with "/"
        while(s1.empty()==false)
        {
            if(s1.size()!=1 )
            {
            ans+=s1.top()+"/";       // need to add "/" after every string except last
            s1.pop();
            }
            else
            {
            ans+=s1.top();
            s1.pop();
            }
        }
        return ans;
        
    }
};
