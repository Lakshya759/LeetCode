class Solution {
public:
    void sortColors(vector<int>& arr) {

        int n=arr.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
                
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
                
            }

            
        }
        
        
        
        // int c0=0,c1=0,c2=0;
        
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         c0++;
        //     }
        //     else if(nums[i]==1){
        //         c1++;
        //     }
        //     else{
        //         c2++;
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(i<c0){
        //         nums[i]=0;
        //     }
        //     else if(i<c0+c1){
        //         nums[i]=1;
        //     }
        //     else{
        //         nums[i]=2;
        //     }
        // }
        // int j=0;
        // if(c0>0){
        //     while(j<n && nums[j]==0){
        //         j++;
        //     }
        // }
        // for(int i=n-1;i>=c0;i--){
        //     if(nums[i]==0){
        //         swap(nums[i],nums[j]);
        //     }
        //     while(j<n && nums[j]==0){
        //         j++;
        //     }
        // }
        // j=c0;
        // if(c1>0){
        //     while(j<n && nums[j]==1){
        //         j++;
        //     }
        // }
        // for(int i=n-1;i>=c0+c1;i--){
        //     if(nums[i]==1){
        //         swap(nums[i],nums[j]);
        //     }
        //     while(j<n && nums[j]==1){
        //         j++;
        //     }
        // }
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        
    }
};