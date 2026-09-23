class Solution {
public:
    vector<int> twoSum(vector<int>& t, int target) {
        map<int,int> mp;
        for(int i=0;i<t.size();i++){
            int temp=target-t[i];
            if(mp.find(temp)!=mp.end()){
                return {mp[temp],i};
            }
            mp[t[i]]=i;
        }
        return {};
    }
};