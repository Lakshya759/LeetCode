class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        vector<int> a=nums;
        int n=nums.size();
        for(int i=0;i<n;i++){
            a.push_back(nums[i]);
        }
        vector<long long> pref((2*n)+1);
        pref[0]=0;
        for(int i=1;i<(2*n)+1;i++){
            pref[i]=pref[i-1]+a[i-1];
        }
        int count=0;
        for(int i=0;i<n;i++){
            int m=n/2;
            long long sum1=pref[i+(m)]-pref[i];
            long long sum2=abs(pref[i+m]-pref[i+n]);
            if(sum1>sum2){
                count++;
            }
        }
        return count;

        
    }
};