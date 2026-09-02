class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return a[0];
        }
        if(a[0]!=a[1]){
            return a[0];
        }
        if(a[n-1]!=a[n-2]){
            return a[n-1];
        }
        int low=1,high=n-2;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(a[mid]!=a[mid+1] && a[mid]!=a[mid-1]){
                return a[mid];
            }
            if(a[mid]==a[mid+1]){
                if(mid%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(mid%2==0){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return 1;
        
    }
};