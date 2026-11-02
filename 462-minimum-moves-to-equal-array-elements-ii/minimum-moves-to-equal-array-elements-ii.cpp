class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int ind=(n+1)/2;
        ind--;
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<n;i++){
            res+=abs(nums[i]-nums[ind]);
        }
        return res;
        
    }
};