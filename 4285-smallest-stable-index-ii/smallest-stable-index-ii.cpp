class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxi,mini;
        int x=nums[0];
        for(int i=0;i<n;i++){
            x=max(x,nums[i]);
            maxi.push_back(x);
        }
        x=nums[n-1];
        for(int i=n-1;i>=0;i--){
            x=min(x,nums[i]);
            mini.push_back(x);
        }
        reverse(mini.begin(),mini.end());
        for(int i=0;i<n;i++){
            if((maxi[i]-mini[i])<=k){
                return i;
            }
        }
        return -1;
    }
};