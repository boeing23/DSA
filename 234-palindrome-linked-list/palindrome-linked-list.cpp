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
    ListNode* reverse(ListNode*root)
    {
        if(!root) return nullptr;
        ListNode*prev=nullptr;
        ListNode*curr=root;

        while(curr!=nullptr)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }


        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        //reverse the half
        ListNode*first=head;

        ListNode*slow=head;
        ListNode*fast=head;


        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast) slow=slow->next;


        ListNode*second=reverse(slow);

        while(first!=nullptr && second!=nullptr)
        {
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;


        }


        return true;
 
        
    }
};