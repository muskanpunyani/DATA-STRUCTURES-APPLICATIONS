< link:      https://leetcode.com/problems/knight-dialer/           >


The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:

Input: n = 3
Output: 46

Example 4:

Input: n = 4
Output: 104

Example 5:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

 

Constraints:

    1 <= n <= 5000

*****************************************************************************************************************


class Solution {
public:
    int mod=pow(10,9)+7;
    int knightDialer(int n) {
        vector<long> arr(10,1);
        for(int i=2;i<=n;i++)
        {
            vector<long> output(10,0);
            output[0]=arr[6]%mod+arr[4]%mod;
            output[1]=arr[6]%mod+arr[8]%mod;
            output[2]=arr[9]%mod+arr[7]%mod;
            output[3]=arr[8]%mod+arr[4]%mod;
            output[4]=arr[0]%mod+arr[3]%mod+arr[9]%mod;
            output[5]=0;
            output[6]=arr[7]%mod+arr[0]%mod+arr[1]%mod;
            output[7]=arr[2]%mod+arr[6]%mod;
            output[8]=arr[3]%mod+arr[1]%mod;
            output[9]=arr[2]%mod+arr[4]%mod;
            arr=output;                 // make arr equal output
        }
        long ans=0;
        for(int i=0;i<=9;i++)
        {
            ans+=arr[i]%mod;
        }
        return ans%mod;
    }
};
