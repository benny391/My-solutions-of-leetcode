class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push_back(x);
        if (f.empty()) {
            f.push_back(x);
        } else {
            if (f.back() < x)
                f.push_back(f.back());
            else 
                f.push_back(x);
        }
    }
    
    void pop() {
        data.pop_back();
        f.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return f.back();
    }
private:
    vector<int> data, f;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
