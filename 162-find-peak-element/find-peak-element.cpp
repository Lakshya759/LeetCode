class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int high=n-2,low=1;
        if(n==1 || a[0]>a[1])return 0;
        if(a[n-1]>a[n-2]) return n-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1])return mid;
            if(a[mid]<a[mid-1]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0;
        
    }
};