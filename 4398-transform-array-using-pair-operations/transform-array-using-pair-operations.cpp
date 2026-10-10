class Solution {
public:
    bool canTransform(vector<int>& s, vector<int>& t) {
        int n=s.size();
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=s[i];
            sum2+=t[i];
        }
        if(sum1==sum2){
            return true;
        }
        return false;
        
    }
};