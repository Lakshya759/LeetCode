class Solution {
public:
    bool check(vector<int>& a) {
        bool flag=0;
        int n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                if(flag){return false;}
                else{
                    flag=1;
                }
            }
        }
        if(flag==0){
            return true;
        }
        if(a[0]<a[n-1]){
            return false;
        }
        return true;
    }
};