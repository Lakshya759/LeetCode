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
        vector<int> nums;
        method1(head,nums);
        int n=nums.size();
        vector<int> maxi;
        for(int i=1;i<n-1;i++){
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                maxi.push_back(i);
            }
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                maxi.push_back(i);
            }
        }
        int m=maxi.size();
        if(m<2)return {-1,-1};
        int res1=maxi[m-1]-maxi[0];
        int res2=INT_MAX;
        for(int i=0;i<m-1;i++){
            int temp=maxi[i+1]-maxi[i];
            res2=min(res2,temp);
        }
        // int maxi1=*max_element(maxi.begin(),maxi.end())-*min_element(mini.begin(),mini.end());
        // int maxi2=*max_element(maxi.begin(),maxi.end())-*max_element(mini.begin(),mini.end());
        // return {abs(maxi1),abs(maxi2)};
        return {res2,res1};

    }
};