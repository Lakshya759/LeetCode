class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
       
        string s=num;
        string s1="";
        for(char c:s){
	    	while(k>0 && !s1.empty() && s1.back()>c){
	    		s1.pop_back();
	    		k--;
	    	}
	    	s1.push_back(c);
	    }
        while(k>0){
	    	s1.pop_back();
	    	k--;
	    }
        int ind=-1;
        
        for(int i=0;i<n;i++){
            if(s1[i]!='0'){
                break;
            }
            else{
                ind++;
            }
        }
        cout<<ind<<endl;
        string res="";
        for(int i=ind+1; i<s1.size();i++){
            res+=s1[i];
        }
        if(res==""){
            res="0";
        }
        
        
        return res;

        
        
    }
};