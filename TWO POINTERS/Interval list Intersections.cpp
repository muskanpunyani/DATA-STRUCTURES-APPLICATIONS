You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:

Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

Example 3:

Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []

Example 4:

Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]

 

Constraints:

    0 <= firstList.length, secondList.length <= 1000
    firstList.length + secondList.length >= 1
    0 <= starti < endi <= 109
    endi < starti+1
    0 <= startj < endj <= 109
    endj < startj+1


*******************************
class Solution {
public:
    /*
    1] we have to find intersecting ramge
    2] the array is already sorted
    3] a------b
          c-------d
         intersection=(c,b)
         i.e max(a,c) as start
         min(b,d) as end
    4] we will merge the intervals after 3rd step as ab can be skipped if we are having cd,i.e longer greating time than that so skip or remove or merge it
    */
    // time=0(n)
    // space=0(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0; // for first list
        int j=0; // for second list
        int n1=firstList.size(); // row
        int n2=secondList.size();
        while(i<n1 && j<n2)
        {
            // first list start and end
            int a=firstList[i][0];
            int b=firstList[i][1];
            // second list start and end
            int c=secondList[j][0];
            int d=secondList[j][1];
            // now find start and end of intersection
            int start=max(a,c);
            int end=min(b,d);
            if(start<=end)
            {
                ans.push_back({start,end});
            }
            if(d>b) // if end of second is greater than first,then we can skip first interval value
            {
            // bcz if a-b and c-d , d was greater than no use of looking 1st interval a-b as its merged with c-d or skipped for next entries
                i++;
            }
            else{ // else vice versa
                j++;
            }
        }
        return ans;
    }
};
