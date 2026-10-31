class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);  
    }
    
    void pop() {    
        st.pop();
    }
    
    int top() { 
        return st.top();
    }
    
    int getMin(){
        vector<int> list;
        int min_ele = INT_MAX;
        while(!st.empty()){
            list.push_back(st.top());
            min_ele = min(min_ele, st.top());
            st.pop();
        }
        reverse(list.begin(), list.end());
        for(auto it : list){
            st.push(it);
        }
        return min_ele;
    }
};
