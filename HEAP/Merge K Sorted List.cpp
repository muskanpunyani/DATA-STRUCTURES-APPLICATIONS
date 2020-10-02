

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

***************************************************************************************************************************************************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
 priority_queue<int,vector<int>,greater<int> > min_heap;
 ListNode* curr=NULL;
 for(auto x:A)   // A is vector of linked list
 {
     curr=x;   
     while(curr!=NULL)   // now for every specific linked list,we need to traverse
     {
     min_heap.push(curr->val);
     curr=curr->next;
     }
 }
 ListNode* ans=new ListNode(0);
 ListNode* temp=ans;
 while(min_heap.empty()==false)
 {
     int value=min_heap.top();
     min_heap.pop();
     ListNode* v=new ListNode(value);   // take out minimum elemnt and put it in ans
     temp->next=v;  // 0->next=v ; v(prev)->next
     temp=temp->next; // temp=v
     
 }
 return ans->next;  // s first 1 is 0 we dont want to take that
}
