class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n=a.size();
        int high=*max_element(a.begin(),a.end());
        int low=1;
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long res=0;
            for(int i=0;i<n;i++){
                res+=(a[i]+mid-1)/mid;

            }
            if(res<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};