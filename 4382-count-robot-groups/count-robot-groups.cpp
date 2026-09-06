class Solution {
public:
    int countGroups(vector<int>& pos, vector<int>& s, int dist) {
        int n=pos.size();
        int count=1;
        for(int i=n-1;i>0;i--){
            if(pos[i]-pos[i-1]<=dist){
                s[i-1]=s[i];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[i+1]){
                if(pos[i+1]-pos[i]>dist){
                    count++;
                }
            }
            if(s[i]<s[i+1]){
                count++;
            }
            else{
                s[i]=s[i+1];
            }
        }
        return count;
        
    }
};