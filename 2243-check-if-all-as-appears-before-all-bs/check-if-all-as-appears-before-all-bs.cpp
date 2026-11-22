class Solution {
public:
    bool checkString(string s) {
        bool flag=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b'){flag=1;continue;}
            if(s[i]=='a' && flag){
                return false;
            }
        }
        return true;
    }
};