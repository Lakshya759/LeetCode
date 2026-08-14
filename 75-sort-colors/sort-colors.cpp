class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int c0=0,c1=0,c2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0++;
            }
            else if(nums[i]==1){
                c1++;
            }
            else{
                c2++;
            }
        }
        int j=0;
        if(c0>0){
            while(j<n && nums[j]==0){
                j++;
            }
        }
        for(int i=n-1;i>=c0;i--){
            if(nums[i]==0){
                swap(nums[i],nums[j]);
            }
            while(j<n && nums[j]==0){
                j++;
            }
        }
        j=c0;
        if(c1>0){
            while(j<n && nums[j]==1){
                j++;
            }
        }
        for(int i=n-1;i>=c0+c1;i--){
            if(nums[i]==1){
                swap(nums[i],nums[j]);
            }
            while(j<n && nums[j]==1){
                j++;
            }
        }
        for(auto it:nums){
            cout<<it<<" ";
        }
        
    }
};