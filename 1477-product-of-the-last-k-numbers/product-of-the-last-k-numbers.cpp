class ProductOfNumbers {
public:
    vector<int> a;
    vector<int> pref;
    

    ProductOfNumbers() {

        pref.push_back(1);
    }
    
    void add(int num) {
        a.push_back(num);
        int n=a.size()-1;
        int x=pref[n]*num;
        pref.push_back(x);
    }
    
    int getProduct(int k) {
        int res=1;
        int n=a.size()-1;
        while(k>0){
            res*=a[n];
            n--;
            k--;
        }
        // int res=pref[n]/pref[n-k];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */