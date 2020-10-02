Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*****************************************************************************************************************************************

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {
    vector<int> v;
    ListNode* temp=A;
    while(temp!=NULL)
    {
        v.push_back(temp->val);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    ListNode* head=new ListNode(0);
    ListNode* curr=head;
    for(int i=0;i<v.size();i++)
    {
        int value=v[i];
        ListNode* ans=new ListNode(value);
        curr->next=ans;
        curr=curr->next;
        
    }
    return head->next;
}
