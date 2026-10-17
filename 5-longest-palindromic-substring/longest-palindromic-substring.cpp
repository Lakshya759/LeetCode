class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int res=1;
        int start=-1,end=-1;
        for(int i=0 ; i<n; i++){
            int j=i;
            int k=i;

            while(s[k]==s[k+1]){
                k++;
            }
            while(j>0 && k<n-1 ){
                if(s[j-1]==s[k+1]){
                    j--;
                    k++;
                }
                else{
                    break;
                }
            }
            if(res<=k-j+1){
                start=j;
                end=k;
                res=k-j+1;
            }
            res=max(res,k-j+1);
        }
        string a=s.substr(start,end-start+1);
        return a;
    }
};