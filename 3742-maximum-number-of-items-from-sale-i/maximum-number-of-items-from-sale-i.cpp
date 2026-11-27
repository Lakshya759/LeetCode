class Solution {
public:
    //factor , price , first count
    // int solve(int ind, int budget,int activated,vector<vector<int>> &a, vector<vector<vector<int>>> &dp){
    //     int n=a.size();
    //     if(budget<=0){
    //         return 0;
    //     }
    //     if(ind>=n){
    //         return 0;
    //     }

    //     if(dp[ind][budget][activated]!=-1){return dp[ind][budget][activated];}

    //     int take=0;
    //     if(budget>=a[ind][1]){
    //         take=solve(ind,budget-a[ind][1],1,a,dp);
    //         if(activated==1){
    //             take++;
    //         }
    //         else{
    //             take+=a[ind][2];
    //         }
    //     }
        
    //     int not_take=solve(ind+1,budget,0,a,dp);
    //     return dp[ind][budget][activated]=max(take,not_take);
    // }
    int solve(int ind,int budget,vector<vector<int>> &a, vector<vector<int>> &dp){
        int n=a.size();
        if(budget<=0){return 0;}
        if(ind>=n){return 0;}
        if(dp[ind][budget]!=-1){return dp[ind][budget];}
        int take=0;
        if(budget>=a[ind][0]){
            take=a[ind][1]+solve(ind+1,budget-a[ind][0],a,dp);

        }
        int notTake=solve(ind+1,budget,a,dp);
        return dp[ind][budget]=max(take,notTake);

    }
    int maximumSaleItems(vector<vector<int>>& item, int budget) {
        int n=item.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(item[j][0]%item[i][0]==0){
                    count++;
                }
            }
            //{price_per_unit_item, min_price, no. of item }
            if(count>1){
                a.push_back({item[i][1],count});
            }
            
        }
        vector<vector<int>> dp(n+1,vector<int>(budget+1,-1));
        int res=INT_MIN;
        int mn=INT_MAX;
        for(auto it :item){
            mn=min(mn,it[1]);
        }
        for(int i=0;i<=budget;i++){
            int temp=solve(0,i,a,dp);
            res = max(res, temp + (budget - i) / mn);
        }
        return res;










        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<budget+1;j++){
        //         for(int k=0;k<2;k++){
        //             if(j<=0){
        //                 dp[i][j][k]=0;
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<budget+1;j++){
        //         for(int k=0;k<2;k++){
        //             if(i>=n){
        //                 dp[i][j][k]=0;
        //             }
        //         }
        //     }
        // }

        // for(int i=n-1;i>=0;i--){
        //     for(int j=1;j<=budget;j++){
        //         for(int k=0;k<2;k++){
        //             int take=0;
        //             if(j>=a[i][1]){
        //                 take=dp[i][j-a[i][1]][1];
        //                 if(k==1){
        //                     take++;
        //                 }
        //                 else{
        //                     take+=a[i][2];
        //                 }
        //             }
        //             int not_take=dp[i+1][j][0];
        //             dp[i][j][k]=max(take,not_take);
        //         }
        //     }
        // }
        
        // return dp[0][budget][0];
        // return solve(0,budget,0,val,dp);
        
        // sort(val.begin(),val.end());
        // for(auto it:val){
        //     cout<<it.second.first<<" ";
        // }
        // cout<<endl;
        // for(auto it:val){
        //     cout<<it.second.second<<" ";

        // }
        // int count=0;
        // for(int i=0;i<val.size();i++){
        //     if(val[i].second.second>1){
        //         if(val[i].second.first<=budget){
        //             count+=val[i].second.second;
        //             budget-=val[i].second.first;
        //         }
        //         continue;
        //     }
        //     while(val[i].second.first<=budget){
        //         count++;
        //         budget-=val[i].second.first;
        //     }
        // }
        // return  count;
    }
};