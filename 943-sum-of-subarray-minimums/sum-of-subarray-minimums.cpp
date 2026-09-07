class Solution {
public:
int mod=1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(n),nxt(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nxt[i]=n;
            }
            else{
                nxt[i]=st.top();
            }
            st.push(i);
        }
       
        int res=0;
        for(int i=0;i<n;i++){
            long long left=i-prev[i];
            long long right=nxt[i]-i;
            long long sum=((left*right)%mod*arr[i])%mod;
            res=(res+sum)%mod;
        }
        return res;

        
    }
};