class ProductOfNumbers {
public:
    vector<int> a;
    vector<int> pref;
    

    ProductOfNumbers() {

        pref.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            a.clear();
            pref.clear();
            pref.push_back(1);
            return;
        }
        a.push_back(num);
        int n=a.size()-1;
        int x=pref[n]*num;
        pref.push_back(x);
    }
    
    int getProduct(int k) {
        // int res=1;
        int n=a.size();
        if(n-k<0){
            return 0;
        }
        
        int res=pref[n]/pref[n-k];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */