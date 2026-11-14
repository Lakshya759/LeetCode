class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int res=INT_MAX;
        for(int i=l;i<r+1;i++){
            
            for(int j=0;j<n;j++){
                int temp=0;
                if(j+i-1>=n){
                    break;
                }
                for(int k=0;k<i;k++){
                    temp+=nums[j+k];
                }
                if(temp>0){
                    res=min(res,temp);
                }
            }
        }
        if(res==INT_MAX){
            return -1;
        }
        return res;
        
    }
};