Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?


*************************
class Solution {
public:
    /*
    1] WE CAN USE STACK WHENEVER GET HASH POP THE TOP BUT THIS WILL TAKE 0(N) SPACE
    */
    /*
    start from last char and if found "#",move back 
    1] let say we are traversing string 1 from end,if we got # we need to skip that char thus skip++
    if not # then skip-- and reduce the string length 2
    do the similar for string 2
    after this comapare the rem char and find ans
    
    //eg s="ab##" t="c#d#"
    traverse s and t from end, 
    ab##, skip=1,skip=2,skip=1,skip=0
    c#d#, skip=1,skip=0,skip=1,skip=0
    now i=-1,j=-1 cant comapre empty string return true
    
    // eg2 s="ab#c" t="ad#c"
    traverse s & t from end
    ab#c ,skip==0,and not "#" thus break
    ad#c , skip==0 and not # thus break
    compare i=3,j=3 ,matced i-- j--
    
    now s[i]=# skip=1, s[i]=b ,skip--,skip=0 break
    similar t[i]=# , skip++,skip=1, t[i]=d,skip=0,break
    compare the char at i n j decrement i & j and go again in while loop
    
    
    
    // 1] while (i>=0|| j>=0)
    while(check s)
    while(check t)
    if(check s[i] && t[j])
    move ahead
    */
    // time=0(n)
    // space=0(1)
    bool backspaceCompare(string S, string T) {
        int n=S.size();
        int m=T.size();
        int i=n-1,j=m-1;
        while(i>=0 || j>=0)
        {
            int skip=0;
            // first string
            while(i>=0)
            {
                if(S[i]=='#')
                {
                    skip++;
                    i--;
                }
                else{  // not #
                    if(skip>0) {
                        skip--;
                        i--;
                    }
                    else            // if skip is 0
                        break;
                }
            }
            // second string
            skip=0;
             while(j>=0)
            {
                if(T[j]=='#')
                {
                    skip++;
                    j--;
                }
                else{  // not #
                    if(skip>0) {
                        skip--;
                        j--;
                    }
                    else            // if skip is 0
                        break;
                }
            }
            if(i>=0 && j>=0 && S[i]!=T[j])
            {
                return false;
            }
            // if comparing char with nothing means one is having char and other nothing
            if((i>=0)!=(j>=0))
            {
                return false;
            }
            i--;
            j--;
            
        }
        return true;
    }
};
