class Solution {
public:
    int reverse(int y) {
        long long temp=0;
        bool flag=0;
        if(y<0){
            flag=1;
        }
        long long x=y;
        x=abs(x);
        while(x>0){
            temp=temp*10+x%10;
            x/=10;
        }
        if(flag){
            temp*=-1;
            if(temp<INT_MIN){
                return 0;
            }
            return temp;
        }
        if(temp>INT_MAX){
            return 0;
        }
        return temp;
        
    }
};