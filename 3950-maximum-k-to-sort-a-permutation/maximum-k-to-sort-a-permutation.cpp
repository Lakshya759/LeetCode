class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int res=(1<<18)-1;
        bool flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                flag=1;
                res=res & nums[i];
            }
        }
        if(!flag){
            return 0;
        }
        return res;

        
    }
};