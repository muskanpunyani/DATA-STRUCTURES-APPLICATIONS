Medium
0 / 50

Given a string str and a number k, find the length of the longest substring in str with exactly k unique characters.

If there are no possible substrings, return -1.
Examples

str: "aabcdaddaf"
k: 3
Explanation:
substrings with k unique characters: ["aabc", "abc", "bcd", "cda", "cdad", "cdadd", "cdadda", "daddaf", "addaf", "ddaf", "daf"]
longest substrings: ["cdadda", "daddaf"]
Result: 6

str: "mississippi"
k: 4
Explanation:
substrings with k unique characters: ["mississip", "mississipp", "mississippi"]
longest substrings: ["mississippi"]
Result: 11

str: "abcdef"
k: 3
Explanation:
substrings with k unique characters: ["abc", "bcd", "cde", "def"]
longest substrings: ["abc", "bcd", "cde", "def"]
Result: 3

str: "aaa"
k: 2
Explanation:
substrings with k unique characters: []
longest substrings: []
Result: -1
********************
bool valid(vector<int>& count,int k)
{
	int c=0;
	for(int i=0;i<26;i++)
	{
		if(count[i]>0)
			c++;
	}
	if(c>k)
		return false;
	
	return true;
}
int longestSubstringWithKUniqueCharacters(string s, int k) {
    // add your logic here
	int n=s.size();
	int left=0;
	int right=0;
	int ans=1;
	vector<int> cnt(26,0);
	int u=0;  // unique elem
	for(int i=0;i<n;i++)
	{
		if(cnt[s[i]-'a']==0) // if unique
			   {
				   u++;
			   }
		cnt[s[i]-'a']++;
	}
	if(u<k)
		return -1;
	
	for(int i=0;i<26;i++)
		cnt[i]=0;
	
	cnt[s[0]-'a']++;  // fisrt char
	//right++;
	// right left is index, initially both are at index 0
	for(int i=1;i<n;i++)
	{
		// valid case
		cnt[s[i]-'a']++;
		right++;
		
		// if invalid case
		if(!valid(cnt,k))
		{
			// if string is having greater than k distinct character
			// move left part of window
			cnt[s[left]-'a']--;
			left++;
		}
		ans=max(ans,right-left+1);
	}
	return ans;
	
}
