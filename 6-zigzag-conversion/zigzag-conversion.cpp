class Solution {
public:
    string convert(string s, int nr) {
        string res="";
        int n=s.size();
        if(nr==1){
            return s;
        }
        int incr=(nr-1)*2;
        for(int i=0;i<nr;i++){
            int j=i;
            while(j<n){
                res+=s[j];
                int temp=(nr-i-1)*2;
                if(j+temp<n && i!=0 && i!=(nr-1)){
                    res+=s[j+temp];
                }
                j+=incr;
            }
        }
        return res;
        
    }
};