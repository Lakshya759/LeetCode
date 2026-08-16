class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            k=k%n;
        }
        if(k==0)return ;
        vector<int> res;
        int ind=n-k;
        for(int i=0;i<n;i++){
            res.push_back(nums[ind]);
            ind=(ind+1)%n;
        }
        nums=res;

    }
};