class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int n=s.size();
        int len=1;
        int j=0;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            while(freq[s[i]-'a']>2){
                freq[s[j]-'a']--;
                j++;
            }
            cout<<i<<" "<<j<<endl;
            len=max(len,i-j+1);
        }
        return len;
    }
};