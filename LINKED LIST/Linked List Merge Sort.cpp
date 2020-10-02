/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* merge(ListNode* A,ListNode* mid_next)
 {
     ListNode* res;
     if(A==NULL)
      return mid_next;
     if(mid_next==NULL)
      return A;
     
     if(A->val <= mid_next->val)
     {
         res=A;
         A->next=merge(A->next,mid_next);
     }
     else{
         res=mid_next;
         mid_next->next=merge(A,mid_next->next);
     }
     return res;
 }
ListNode* Solution::sortList(ListNode* A) {
  if(A==NULL || A->next==NULL)  // if length of linked list is 0 or 1,it is already sorted
  {
      return A;
  }
  ListNode* slow=A;
  ListNode* fast=A->next;
  while(fast!=NULL && fast->next!=NULL)  // when fast reaches end,slow reaches mid
  {
      slow=slow->next;
      fast=fast->next->next;
  }
  // now slow reached mid
  ListNode* mid_next=slow->next;  // mid+1
  slow->next=NULL;
  ListNode* l1=sortList(A);         // here we are not passig head ref,therefore can't pass A and midnext directly to merge function
  ListNode* l2=sortList(mid_next);
  return merge(l1,l2);
}
