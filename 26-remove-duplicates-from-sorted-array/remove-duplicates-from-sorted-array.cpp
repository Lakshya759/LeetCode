class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        int count=0;
        res.push_back(nums[0]);
        count++;
        for(int i=1;i<n;i++){
            
            if(nums[i]!=nums[i-1]){
                
                count++;
                res.push_back(nums[i]);
            }
        }
        for(int i=0;i<res.size();i++){
            nums[i]=res[i];
            
        }
        nums=res;
        return count;
    }
};