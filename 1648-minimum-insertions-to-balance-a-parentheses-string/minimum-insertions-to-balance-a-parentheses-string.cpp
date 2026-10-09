class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int cnt=0;
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                str+='(';
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    str+=')';
                    i++;
                }
                else{
                    str+=')';
                    cnt++;
                }
            }
        }
        int count=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                count++;
            }
            else{
                if(count>0){
                    count--;
                }
                else{
                    cnt++;
                }
            }
        }
        cnt+=2*abs(count);
        return cnt;
        
    }
};