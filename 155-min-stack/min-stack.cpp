class MinStack {
public:
    vector<int> a;
    vector<int> mini;
    int ind;
    MinStack() {
        ind=-1;
    }
    
    void push(int value) {
        a.push_back(value);
        ind++;
        if(ind==0){
            mini.push_back(a[ind]);
        }
        else{
            mini.push_back(min(mini[ind-1],a[ind]));
        }
    }
    
    void pop() {
        if(ind==-1){
            return;
        }
        a.pop_back();
        mini.pop_back();
        ind--;
    }
    
    int top() {
        if(ind==-1){
            return -1;
        }
        return a[ind];
    }
    
    int getMin() {
        if(ind==-1){
            return -1;
        }
        return mini[ind];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */