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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode*dummy=new ListNode(); //this creates a new node;
        //now a pointer to the new node

        ListNode*curr=dummy;

        int carry=0;
      

        while(l1!=nullptr || l2!=nullptr || carry!=0)
        {

            int v1,v2,sum;
            if(l1!=nullptr) v1=l1->val;
            else v1=0;

            if(l2!=nullptr) v2=l2->val;
            else v2=0;



         sum= v1+v2+carry;

            carry=sum/10;

            curr->next=new ListNode(sum%10);
            curr=curr->next;

            if(l1) l1=l1->next;
            else l1=nullptr;


            if(l2) l2=l2->next;
            else l2=nullptr;



        }

        ListNode* res=dummy->next;
        delete dummy;

        return res;
        
    }
};