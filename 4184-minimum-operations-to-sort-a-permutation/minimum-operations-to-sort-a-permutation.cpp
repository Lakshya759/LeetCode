class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        // AGAR ALREADY SORTED HAI TOH 0 STEPS
        bool flag=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                flag=0;
                break;
            }
        }
        if(flag){
            return 0;
        }
        flag=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=(n-i-1)){
                flag=0;
                break;
            }
        }
        if(flag){
            return 1;
        }


        // CHECK KI KHA 0 aa rha hai
        
          
        bool f1=(nums[0]<nums[1]);
        int count=0;
        int ind=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ind=i;
                break;
            }
        }
        

        // if(ind==0){
        //     return -1;
        // }

        // GENERATING THE NEW ARRAY
        vector<int> nr;
        int res=0;

        if(nums[(ind+1)%n]==1){
            for(int i=0;i<n;i++){
                nr.push_back(nums[(ind+i)%n]);
            }
            bool flag=1;
            for(int i=0;i<n;i++){
                if(nr[i]!=i){
                    flag=0;
                    break;
                }
            }
            if(flag){
                int res=min(ind,n - ind+2);
                return res;
            }
            else{
                return -1;
            }

        }
        else if(nums[(ind-1+n)%n]==1){
            // cout<<"2nd case";
            ind;
            for(int i=0;i<n;i++){
                // cout<<nums[(ind+i)%n]<<" ";
                nr.push_back(nums[(ind+1+i)%n]);
            }
            reverse(nr.begin(),nr.end());
            bool flag=1;
            for(int i=0;i<n;i++){
                if(nr[i]!=i){
                    flag=0;
                    break;
                }
            }
            if(flag){
                int res=min(ind+2,n - ind);
                return res;
            }
            else{
                return -1;
            }

            // bool flag=1;
            // int count=n-1;
            // for(int i=0;i<n;i++){
                
            //     if(nr[i]!=count){
            //         flag=0;
            //         break;
            //     }
            //     count--;
            // }
            // if(flag){
            //     ind--;
            //     int res=min(ind+1,n-ind-1);
            //     return res+1;
            // }
            // else{
            //     return -1;
            // }
        }
        return -1;
        
        
        


        // CHECKING IF THE NEW ARRAY IS SORTED OR NOT
        


        
    }
};