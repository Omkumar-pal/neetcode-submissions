class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    int min_ele = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty()){
            st2.push(val);
        }
        else if (st2.top() >= val){
            st2.push(val);
        }
        
    }
    
    void pop() {    
        if(!st2.empty() && st2.top() == st1.top()){
            st2.pop();
            st1.pop();
        }else{
            st1.pop();
        }
    }
    
    int top() { 
        return st1.top();
    }
    
    int getMin(){
        return st2.top();
    }
};
