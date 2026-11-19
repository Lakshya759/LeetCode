class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        
        int low=nums[n-1]-nums[2];
        int high=nums[n-3]-nums[0];
        int x=nums[n-2]-nums[1];
        return min(low,min(high,x));
        
    }
};