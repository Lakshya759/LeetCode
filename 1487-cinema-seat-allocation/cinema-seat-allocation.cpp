class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>> mp;
        for(auto it:reservedSeats){
            mp[it[0]]={1,1,1};
        }
       

        for(auto it:reservedSeats){
            if(it[1]==2 || it[1]==3){
                mp[it[0]][0]=0;
                
            }
            if(it[1]==4 || it[1]==5){
                mp[it[0]][0]=0;
                mp[it[0]][1]=0;
            }
            if(it[1]==6 || it[1]==7){
                mp[it[0]][2]=0;
                mp[it[0]][1]=0;
            }
            if(it[1]==8 || it[1]==9){
                mp[it[0]][2]=0;
            }
        }
        
        int sum=(n-mp.size())*2;
        for(auto it:mp){
            if(it.second[1] && it.second[0] && it.second[2]){
                sum+=2;
            }
            else if(it.second[1]){
                sum+=1;
            }
            else{
                sum+=it.second[0]+it.second[2];
            }
        }
        return sum;
        
    }
};