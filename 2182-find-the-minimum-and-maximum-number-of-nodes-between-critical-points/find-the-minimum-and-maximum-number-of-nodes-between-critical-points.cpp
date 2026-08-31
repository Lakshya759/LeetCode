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
    void method1(ListNode* head,vector<int> &nums){
        if(head==NULL)return;
        nums.push_back(head->val);
        method1(head->next,nums);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       int first=-1,last=-1;
       int prev=-1;
       int prevNum=head->val;
       int res2=INT_MAX;
       
       ListNode* temp=head->next;
       int ind=1;
       while(temp->next!=NULL){
            bool flag=false;
            if(temp->val>prevNum && (temp->val)>(temp->next->val)){
            flag=true;
            }
            if(temp->val<prevNum && (temp->val)<(temp->next->val)){
            flag=true;
            }
            if(flag){
                if(first==-1){first=ind;}
                if(prev!=-1){res2=min(res2,ind-prev);}
                prev=ind;
            }
            prevNum=temp->val;
            ind++;
            temp=temp->next;


       }
       if(prev==first){return {-1,-1};}

       int res1=prev-first;
       return {res2,res1};
    }
};