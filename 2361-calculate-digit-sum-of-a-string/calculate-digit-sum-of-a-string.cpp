class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        string res=s;
        while(res.size()>k){
            string temp="";
            int cnt=0;
            int sum=0;

            for(int i=0;i<res.size();i++){
                sum+=res[i]-'0';
                cnt++;
                if(cnt==k){
                    temp+=to_string(sum);
                    sum=0;
                    cnt=0;
                }


            }
            if(res.size()%k!=0){
                temp+=to_string(sum);
            }
            cout<<res<<endl;
            res=temp;
        }
        return res;
        
    }
};