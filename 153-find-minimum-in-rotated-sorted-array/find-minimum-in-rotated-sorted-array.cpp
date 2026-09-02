class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int res=a[0];
        int high=n-1,low=0;
        while(high>=low){
            int mid=low+((high-low)/2);
            if(a[mid]>=a[0]){
                low=mid+1;
            }
            else{
                res=min(res,a[mid]);
                high=mid-1;
            }
        }
        return res;
    }
};