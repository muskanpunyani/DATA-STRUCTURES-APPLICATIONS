Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

*********************************************************************************************************************


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
    ListNode* rotateRight(ListNode* head, int k) {
        // TAKE OUT THE LAST ELEMENT K TIMES AAND INSERT IT IN FRONT OF LIST
         if(head==NULL || head->next==NULL)
        {
            return head;
        }
       
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL)  // find length of list
        {
            length++;
            temp=temp->next;
        }
        if(k>length)   // if k is greater than linked list 
        {
            k=k%length;
        }
       
       
        while(k>0)
        {
             ListNode* last=head;
             while(last->next->next!=NULL)   // now the last is having 2nd last element
             {
               last=last->next;
             }
        
            ListNode *t=new ListNode(last->next->val);   // create a new node with last value
            last->next=NULL;              // make 2nd last point to null and remove last
            t->next=head;             // insert last to front
            head=t;                    // change the head
            k--;                     // decrease k
            
        }
        return head;
    }
};
