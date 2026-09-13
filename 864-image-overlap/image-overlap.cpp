class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img2.size();
        int res=0;
        //Right-Down
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                int t1=0;
                int t2=0;
                for(int r=0;r<n-i;r++){
                    t2=0;
                    for(int c=0;c<m-j;c++){
                        if(img1[r][c]==img2[r+i][c+j] && img1[r][c]==1){
                            cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
                            count++;
                        }
                        t2++;
                    }
                    t1++;
                }
                // cout<<count<<" "<<i<<" "<<j<<endl;
                res=max(res,count);
            }
        }
        
        //Left-Down
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                int t1=0;
                int t2=0;
                for(int r=0;r<n-i;r++){
                    t2=0;
                    for(int c=j;c<m;c++){
                        if(img1[r][c]==img2[r+i][c-j] && img1[r][c]==1){
                            count++;
                        }
                        t2++;
                    }
                    t1++;
                }
                res=max(res,count);
            }
        }
        
       
        //Left-Up
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t1=0;
                int count=0;
                for(int r=i;r<n;r++){
                    int t2=0;
                    for(int c=j;c<m;c++){
                        if(img1[r][c]==img2[r-i][c-j] && img1[r][c]==1){
                            count++;
                        }
                        t2++;
                    }
                    t1++;
                }
                res=max(res,count);
            }
        }
        
       
        //Right-Up
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                int t1=0;
                for(int r=i;r<n;r++){
                    int t2=0;
                    for(int c=0;c<m-j;c++){
                        if(img1[r][c]==img2[r-i][c+j] && img1[r][c]==1){
                            count++;
                        }
                        t2++;
                    }
                    t1++;
                }
                res=max(res,count);
            }
        }
        
       
        return res;




        
    }
};