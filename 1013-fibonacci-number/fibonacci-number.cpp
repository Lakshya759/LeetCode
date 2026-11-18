class Solution {
public:
    int fib(int n) {
        int llast=1,last=1;
        if(n==1 || n==2){
            return 1;
        }
        int curr=0;
        for(int i=0;i<n-2;i++){
            curr=llast+last;
            llast=last;
            last=curr;
        }
        return curr;

        
    }
};