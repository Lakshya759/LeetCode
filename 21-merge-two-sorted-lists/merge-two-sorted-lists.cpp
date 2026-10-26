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
    void solve(ListNode* l1, ListNode* l2, ListNode* res){
        if(l1==NULL && l2==NULL){
            return ;
        }
        ListNode* node=new ListNode();
        if(l1==NULL){
            node->val=l2->val;
            res->next=node;
            solve(l1,l2->next,res->next);
        }
        else if(l2==NULL){
            node->val=l1->val;
            res->next=node;
            solve(l1->next,l2,res->next);
        }
        else if(l1->val>l2->val){
            node->val=l2->val;
            res->next=node;
            solve(l1,l2->next,res->next);
        }
        else{
            node->val=l1->val;
            res->next=node;
            solve(l1->next,l2,res->next);
        }
        
    }
    ListNode* solve2(ListNode* l1, ListNode* l2){
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        ListNode* node=new ListNode();
        bool flag=0;
        if(l1==NULL || (l2!=NULL && l1->val >= l2->val)){
            node->val=l2->val;

        }
        else{
            node->val=l1->val;
            flag=1;
        }
        if(flag){
            node->next=solve2(l1->next,l2);
        }
        else{
            node->next=solve2(l1,l2->next);
        }
        return node;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ListNode* node=new ListNode();
        // solve(l1,l2,node);
        // node=node->next;
        // return node;
        return solve2(l1,l2);
    }
};