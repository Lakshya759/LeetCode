class Solution {
public:
    int scoreOfParentheses(string s) {
       int n=s.size();
       int cnt=0;
       int res=0;
       int temp=0;
       
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;

        }
        if(s[i]==')'){
            cnt--;
            if(s[i-1]=='('){
                res+=1<<cnt;
            }
            
            
        }
        
       } 
       return res;
    }
    
};