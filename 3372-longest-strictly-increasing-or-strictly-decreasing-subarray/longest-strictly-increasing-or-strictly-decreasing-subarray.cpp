class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=1;
        for(int i=0;i<n;i++){
            int c1=1,c2=1;
            for(int j=i;j<n-1;j++){
                if(nums[j]<nums[j+1]){
                    c1++;
                }
                else{
                    break;
                }
            }
            for(int j=i;j<n-1;j++){
                if(nums[j]>nums[j+1]){
                    c2++;
                }
                else{
                    break;
                }
            }
            res=max(res,max(c1,c2));

        }
        return res;
    }
};