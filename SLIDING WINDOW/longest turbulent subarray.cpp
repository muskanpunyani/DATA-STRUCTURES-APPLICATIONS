Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

    For i <= k < j:
        arr[k] > arr[k + 1] when k is odd, and
        arr[k] < arr[k + 1] when k is even.
    Or, for i <= k < j:
        arr[k] > arr[k + 1] when k is even, and
        arr[k] < arr[k + 1] when k is odd.

 

Example 1:

Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]

Example 2:

Input: arr = [4,8,12,16]
Output: 2

Example 3:

Input: arr = [100]
Output: 1

 

Constraints:

    1 <= arr.length <= 4 * 104
    0 <= arr[i] <= 109




class Solution {
public:
    // time=0(n)
    // space=0(1)
    int value(int a,int b)
    {
          if(a>b)
            {
                return 1;
            }
            else if(a<b)
            {
                return -1;
            }
           return 0;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int start=0;
       int i=0;
        int ans=1;
        int n=arr.size();
        for( i=1;i<n;i++)
        {
            // finding value for i-1
            int c=value(arr[i-1],arr[i]);
            if(c==0) // go to next block
            {
                start=i;
            }
            // if end or find val of next i.e i
            // 1*-1=-1 ,-1*1=-1, for other i.e 1*1 and -1*-1=1,sequence end,thus end of that block
            else if(i==n-1 || c*value(arr[i],arr[i+1])!=-1){ // end
              ans=max(ans,i-start+1);
                start=i;
            }
        }
        return ans;
     
    }
};
