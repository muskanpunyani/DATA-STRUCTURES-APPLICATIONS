Given an array A, find the length of the longest subarray which has a sum equal to 0.
Example

A: [3, 0, -1, -2, 3, 0, -2]
Result: 5
Explanation: Longest Subarray with sum 0: [0, -1, -2, 3, 0]

Testing
Input Format

The first line contains an integer ‘T’ denoting the number of test cases.
For each test case, the input has two lines:

    An integer ‘n’ denoting the length of the array A.
    n space-separated integers denoting the elements of the array A.

Output Format

For each test case, the output contains a line with one integer denoting the length of the longest subarray with a sum equal to 0.
Sample Input

3
7
3 0 -1 -2 3 0 -2
9
1 2 3 4 5 0 0 -1 1
4
1 -4 2 1

Expected Output

5
4
4

Constraints

1 <= T <= 10
1 <= n <= 105
-109 <= Ai <= 109

******************88
int longestSubarrayWithZeroSum(vector<int> &A) {
    // add your logic here
	/*
	 1. if we find the same sum , then j-i
	 2. if prefix sum is 0, prefix length would be ans
	 3. if 1 and 2 doesn't satisfy update map entry with that elem
	 
	 we are not updating any elem in map if it is occurring again
	 only the first occurunce is noted 
	 bcz we need max size
	 
	 time=0(n)
	 
	 */
	int len=0;
	unordered_map<int,int> m;
	int sum=0;
	for(int i=0;i<A.size();i++)
	{
		sum+=A[i];
		if(sum==0)
		{
			// prefix sum is 0
			len=max(len,i+1);
		}
		else if(m.find(sum)!=m.end())
		{
			// if we found the same sum in map
			len=max(len,i-m[sum]);
			//cout<<i<<" "<<m[sum]<<endl;
		}
		else{
		m[sum]=i;
		}
	}
	return len;
}
