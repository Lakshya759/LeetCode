class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        s=s+s;
        int res=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n-1;j++){
                int ind=i+j;
                if(s[ind]==s[ind+1]){
                    count++;
                }
            }
            if(count==k){
                res++;
            }
        }
        return res;
    }
};