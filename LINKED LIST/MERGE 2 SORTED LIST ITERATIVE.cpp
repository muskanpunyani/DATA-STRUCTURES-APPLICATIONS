You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
****************************
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
    time=0(n) , space=0(1)
    1. node of 2nd list lies bn two nodes of first list then insert that node in bn and chnage the pointers
    2. if does not lie then check if first list still exists then move ahead, if first list empty then attach it with the second one as both are sorted
    3. we will set a standard make the h1 node less than h2 so as to check the h2 nodes lies bn h1
    */
    ListNode* merge(ListNode* h1,ListNode*h2)
    {
        // base cases
        if(h1->next==NULL)
        {
            h1->next=h2;
            return h1;
        }
        ListNode* curr1,*next1,*curr2,*next2;
        curr1=h1;
        next1=h1->next;
        curr2=h2;
        next2=h2->next;
        while(next1 && curr2) // not null
        {
            // if curr2 lies bn next1 and curr1
            if(((curr2->val) >= (curr1->val)) && ((curr2->val) <=(next1->val)))
            {
                next2=curr2->next;  // move ahead in h2 list
                curr1->next=curr2;  // make curr2 in centre
                curr2->next=next1;
                
                // move the heads ahead
                curr1=curr2;
                curr2=next2;
            }
            else{
                // node doesn't lie in bn
                if(next1->next) // if h1 has more nodes
                {
                    curr1=curr1->next;
                    next1=next1->next;
                }
                else{
                    // no more nodes, point 1d=st end to 2nd curr head
                    next1->next=curr2;
                    return h1;
                }
            }
        }
        return h1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if any of the list is empty merge willresult in 2nd list
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        if(list1->val < list2->val)  // if normal case h1 is less
        {
            return merge(list1,list2);
        }
        //if(list2->val < list1->val)   // abnormal case when h2 is smaller so reverse h1 and h2
        else
         return merge(list2,list1); 
        
    }
};
