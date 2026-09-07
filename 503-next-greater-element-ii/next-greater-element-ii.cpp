class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a=nums;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]);
        }

        int n=a.size();
        vector<int> mini(n);
        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=a[i]){
                st.pop();
            }
            if(st.empty()){
                mini[i]=-1;
            }
            else{
                mini[i]=st.top();
            }
            st.push(a[i]);

        }
        vector<int> res;
        for(int i=0;i<(n/2);i++){
            res.push_back(mini[i]);
        }
        return res;
    }
};