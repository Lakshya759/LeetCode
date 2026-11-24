class Solution {
public:
    int maxLength(vector<int>& a) {
        int n=a.size();
        int res=0;
        for(int i=0;i<n;i++){
            __int128 prod=1;
            long long g=a[i];
            long long l=a[i];
            for(int j=i;j<n;j++){
                prod*=a[j];
                g=gcd(g,a[j]);
                l=lcm(l,a[j]);
                if(prod==(g*l)){
                    res=max(res,j-i+1);
                }
                if (prod > 1000000000LL)
                    break;
            }
        }
        return res;
        
    }
};