class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int n=d.size();
        vector<int> mp(10,0);
        for(int i=0;i<n;i++){
            mp[d[i]]++;
        }
        int res=0;
        for(int i=100;i<=999;i++){
            if(i%2!=0){continue;}
            vector<int> cnt(10,0);
            int temp=i;
            for(int j=0;j<3;j++){
                cnt[temp%10]++;
                temp/=10;
            }
            bool flag=1;
            for(int i=0;i<10;i++){
                if(cnt[i]>mp[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                res++;
            }
        }
        return res;

        
        
        
    }
};