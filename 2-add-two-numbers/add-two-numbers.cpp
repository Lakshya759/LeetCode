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
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        struct ListNode* temp1=t2;
        while(t1 !=nullptr && t2 !=nullptr){
            int x=t1->val+t2->val+carry;
            
            if(x>=10){
                carry=1;
                x=x-10;

            }
            else{
                carry=0;
            }
            t1->val=x;
            t2->val=x;
            t1=t1->next;
            t2=t2->next;
            if(t2!=nullptr){
                temp1=t2;
            }

        }
        if(t1==nullptr && t2==nullptr){
            if(carry!=0){
                
                temp1->next=new ListNode(carry);

            }
            return l2;
        }
        else if(t1==nullptr){
            struct ListNode* temp=t2;
            while(t2!=nullptr){
                int x=t2->val+carry;
                if(x>=10){
                    carry=1;
                    x=x-10;
                }
                else{
                    carry=0;
                }
                t2->val=x;
                t2=t2->next;
                if(t2!=nullptr){
                    temp=t2;
                }

            }
            if(carry!=0){
                temp->next=new ListNode(carry);

            }
            return l2;
        }
        else{
            struct ListNode* temp=t1;
            while(t1!=nullptr){
                int x=t1->val+carry;
                if(x>=10){
                    carry=1;
                    x=x-10;
                }
                else{
                    carry=0;
                }
                t1->val=x;
                t1=t1->next;
                if(t1!=nullptr){
                    temp=t1;
                }


            }
             if(carry!=0){
                temp->next=new ListNode(carry);

            }
            return l1;
        }
    }
};