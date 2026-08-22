class Solution {
public:
    void solve(int close,int open,vector<string> &res,string &s){
        int n=s.size();
        if(close==0 && open==0){
            res.push_back(s);
            return ;
        }
        
        if(open<close){
            s.push_back(')');
            solve(close-1,open,res,s);
            s.pop_back();
        }
        if( (open>0)){
            s.push_back('(');
            solve(close,open-1,res,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        
        solve(n,n,res,s);
        return res;
    }
};