class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& a, int k) {
        int n=a.size();

        //Next greatest element
        vector<int> NGE(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]<a[i]){
                NGE[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        //prefix sum generation
        vector<long long> pref(n+1);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+a[i];
        }

        auto rangeSum= [&](int l,int r){
            if(l>r){return 0LL;}
            else{
                return 1LL*(pref[r+1]-pref[l]);
            }
        };

        //operation array formation
        vector<long long> operat(n+1,0);
        for(int i=n-1;i>=0;i--){
            int m=NGE[i];
            long long x=((1LL*(m-i)*a[i])-(rangeSum(i,m-1)));
            operat[i]=operat[m]+x;
        }

        //Applying sliding window maximum
        long long ans=0;
        int i=0,j=0;
        deque<int> dq;
        while(j<n){
            while(!dq.empty() && a[dq.back()]<a[j]){
                dq.pop_back();
            }
            dq.push_back(j); 
            while(i<=j){
                int ngr=dq.front();
                int x=(operat[i]-operat[ngr]) + ((j-ngr+1)*1LL*a[ngr]) - rangeSum(ngr,j);
                if(x<=k){
                    break;
                }
                i++;
                if(dq.front()<i){
                    dq.pop_front();
                }
            }
            ans+=j-i+1;
            j++;
        }
        return ans;



        
    }
};