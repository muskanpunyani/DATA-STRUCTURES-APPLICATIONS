Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.

Example 1:

Input: nums = [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47

Example 2:

Input: nums = [1, 1], target = 2
Output: 1
Explanation:
1 + 1 = 2

Example 3:

Input: nums = [1, 5, 1, 5], target = 6
Output: 1
Explanation:
[1, 5] and [5, 1] are considered the same.

Related problems:

    https://leetcode.com/problems/two-sum
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted


************************************************************************************
#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;
// Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.
// https://leetcode.com/discuss/interview-question/372434

/*
Approach 1: Use an appraoch similar to 2sum and then store pair into a set and return the set size (the pair in the set is sorted) --> o(n), set size is o(n)
Approach 2: Use a 2 pointer appraoch by first sorting the array in increasing order so that we can keep track of duplicates. Keep track of the last valid pair's larger number and only count up if it is unique
	Time Complexity o(nlogn) Space complexity o(1);
*/

int countUniquePairs(vector<int> nums, int target){
	sort(nums.begin(), nums.end());

	int lastValidPairLarger = INT_MIN;
	int left = 0, right = nums.size() -1;
	int count = 0;

	while(left < right){
		int currSum = nums[left] + nums[right];
		if (currSum == target){
			if(lastValidPairLarger != nums[right]){
				count++;
			}
			lastValidPairLarger = nums[right];
			left++; right--;
		} else if (currSum < target){
			left++;
		} else{
			right--;
		}
	}

	return count;
}

int countUniquePairs_optimized(vector<int> nums, int target){
	unordered_set<int> seen;
	unordered_set<int> numsSet;
	int count = 0;

	for (int n : nums){
		int complement = target - n;
		if (numsSet.find(complement) != numsSet.end()){ // since we didnt add everything to the set yet, then we won't hit the case where the pair is itself. 
			// We found the complement
			if(seen.find(complement) == seen.end()){ // we have not seen this number yet
				count++;
			}
			seen.insert(n); // we have now seen/used this number for the overall count of unqiue pairs
			seen.insert(complement); 	// We can either add its complement or check for both the complement and n in seen in line 49. I think this way is faster.. slightly. We have to add its complement because
			// we might get to a case where we double count once we get to the complement number since it doesnt know we have seen n before and counted it. 
		}
		numsSet.insert(n);
	}
	return count;

}

int main (void){
	vector<int> test1 = {1, 1, 2, 45, 46, 46};
	int target1 = 47;
	vector<int> test2 = {1, 1};
	int target2 = 2;
	vector<int> test3 = {1, 5, 1, 5};
	int target3 = 6;
	int res = countUniquePairs_optimized(test3, target3);
	cout << "result is " << res << endl;
	return 0;
}
