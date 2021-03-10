Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.

Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true

Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.

 

Constraints:

    1 <= name.length <= 1000
    1 <= typed.length <= 1000
    name and typed contain only lowercase English letters.


*************
class Solution {
public:
    // time=0(n1+n2)
    // space=0(1);
    bool isLongPressedName(string name, string typed) {
        int n1=name.length();
        int n2=typed.length();
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if( name[i]==typed[j]) // if match
            {
                i++;
                j++;
            }
            else if( name[i]!=typed[j] && j!=0 && typed[j]==typed[j-1]) // if not match skip j,i.e typed
            {
                j++;
            }
            else{
                return false;
            }
        }
        // if there are still char left
        if(i!=n1)  // 1] if char left in original string then ans false
        {
            return false;
        }
        else{   // if char left in typed string,ans can still be true
            while(j<n2)
            {
                if(j!=0 && typed[j]!=typed[j-1])
                {
                    return false;
                }
                j++;
            }
        }
       
            
        return true;
    }
};
