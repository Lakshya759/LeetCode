class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> mini(m);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mini[i]=-1;
            }
            else{
                mini[i]=st.top();

            }
            st.push(nums2[i]);
        }
        map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]=mini[i];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int x=mp[nums1[i]];
            res.push_back(x);
        }
        return res;
        
    }
};