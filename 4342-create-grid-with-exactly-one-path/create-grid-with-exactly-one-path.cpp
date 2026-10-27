class Solution {
public:
    vector<string> createGrid(int n, int m) {
        string s=string(m,'#');
        vector<string> res(n,s);
        
        for(int i=0;i<m;i++){
            res[0][i]='.';
        }
        for(int i=0;i<n;i++){
            res[i][m-1]='.';
        }
        return res;
        
    }
};