Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3

Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.

 

Constraints:

    1 <= arr.length <= 5 * 104
    0 <= arr[i] < arr.length
    0 <= start < arr.length



**************************
class Solution {
public:
    /*
    from start i can go in 2 dirn,startr+arr[start] or start-arr[start]
    if we can reach to value 0 with any path return true
    
    dfs
    */
    bool isvalid(int i,vector<int>& arr)
    {
        int n=arr.size();
        if(i<0 ||i>=n || arr[i]==-1)
            return false;
        return true;
    }
    bool dfs(int start,vector<int>& arr)
    {
        if(!isvalid(start,arr))
        {
            return false;
        }
        if(arr[start]==0)
        {
            return true;
        }
        int temp=arr[start]; 
        arr[start]=-1;    // make it -1,so that we are not taking duplicate values
       bool ans= dfs(start+temp,arr) || dfs(start-temp,arr);
        arr[start]=temp;  // make it back to normal
        return ans;
      
    }
    bool canReach(vector<int>& arr, int start) {
      if(arr[start]==0)
          return true;
        bool ans=dfs(start,arr);
        return ans;
    }
};
