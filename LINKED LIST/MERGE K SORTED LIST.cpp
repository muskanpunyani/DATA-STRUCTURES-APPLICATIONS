You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4
******************************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
    this que can be done using divide and conquer + merge 2 sorted list
    divide into 2 2 parts and apply merge 2 sorted list
    time=0(kn)
    space=0(1)
    */
    ListNode* merge2list(ListNode* h1,ListNode* h2)
    {
        if(h1==NULL)
            return h2;
        if(h2==NULL)
            return h1;
        if(h1->val > h2->val)
            return merge2list(h2,h1);
        if(h1->next==NULL)
        {
            h1->next=h2;
            return h1;
        }
        ListNode* curr1,*curr2,*next1,*next2;
        curr1=h1;
        next1=h1->next;
        curr2=h2;
        next2=h2->next;
        while(next1 && curr2){
            if(curr2->val >=curr1->val && curr2->val<=next1->val)
            {
                next2=curr2->next;
                curr1->next=curr2;
                curr2->next=next1;
                
                curr1=curr2;
                curr2=next2;
            }
            else{
                if(next1->next)
                {
                    next1=next1->next;
                    curr1=curr1->next;
                }
                else{
                    next1->next=curr2;
                    return h1;
                }
            }
        }
        return h1;
    }
    ListNode* merge(vector<ListNode*>& lists,int start,int end)
    {
        if(start==end)
            return lists[start];
        if(start+1==end)
            return merge2list(lists[start],lists[end]);
        
        int mid=((start+end)/2);
        ListNode* l1=merge(lists,start,mid);
        ListNode* l2=merge(lists,mid+1,end);
        return merge2list(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
        int start=0;
        int end=n-1;
        return merge(lists,start,end);
    }
};
