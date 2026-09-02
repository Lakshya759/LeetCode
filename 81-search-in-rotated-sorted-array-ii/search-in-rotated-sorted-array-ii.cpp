class Solution {
public:
    bool search(vector<int>& a, int target) {
        int n=a.size();
        int high=n-1,low=0;
        while(high>=low){
            int mid=low+((high-low)/2);
            if(a[mid]==target){
                return true;
            }
            if(a[mid]==a[low] && a[mid]==a[high]){
                high--;
                low++;
                continue;
            }
            if(a[mid]>=a[low]){
                if(target<=a[mid]&& target>=a[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            
            else{
                if(target>=a[mid] && target<=a[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};