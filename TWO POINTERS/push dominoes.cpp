There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Note:

    0 <= N <= 10^5
    String dominoes contains only 'L', 'R' and '.'


**********************
// time=0(n)
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.length();
        int forces[n+1];  // forces array
        for(int i=0;i<n;i++)
        {
            forces[i]=0;
        }
        int force=0;
        for(int i=0;i<n;i++) // going left to right
        {
            // whenever we get right,make force N,anf for L make force 0
            if(dominoes[i]=='R')
            {
                force=n;
            }
            else if(dominoes[i]=='L')
            {
                force=0;
            }
            else{  // reduce force when "."
                force=max(0,force-1);
            }
            forces[i]+=force;   // +ve for right
            
        }
          force=0;
        for(int i=n-1;i>=0;i--) // going right to left
        {
            // whenever we get left force=n
            if(dominoes[i]=='L')
            {
                force=n;
            }
            else if(dominoes[i]=='R')
            {
                force=0;
            }
            else{  // reduce force when "."
                force=max(0,force-1);
            }
            forces[i]-=force;   // just negative for left
            
        }
        string ans;
        for(int i=0;i<n;i++)
        {
            if(forces[i]>0) //+ve
            {
                ans+='R';
            }
            else if(forces[i]<0)  // -ve
            {
                ans+='L';
            }
            else{  // equal to 0
                ans+='.';
            }
        }
        return ans;
    }
};
