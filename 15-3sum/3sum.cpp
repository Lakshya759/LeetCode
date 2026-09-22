class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if (i>0 && nums[i]==nums[i-1])
                continue;
            int sum=-1*(nums[i]);
            unordered_map<int,int> mp;
            for(int j=i+1;j<n;j++){
                int temp=sum-nums[j];
                if(mp.find(temp)!=mp.end()){
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(temp);
                    sort(a.begin(),a.end());
                    res.push_back(a);
                    while (j+1<n && nums[j]==nums[j+1])
                        j++;
                }
                mp[nums[j]]++;
            }
            
            
        }
        vector<vector<int>> ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;

        
    }
};