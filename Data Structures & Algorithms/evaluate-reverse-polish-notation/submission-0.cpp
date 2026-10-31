class Solution {
public:
    int operation(int &a, int &b, string c){
        if (c == "+"){
            return a + b;
        }else if (c == "-"){
            return a-b;
        }else if (c == "*"){
            return a*b;
        }
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if (it == "+" || it == "-" || it == "*" || it == "/"){
                //ordering
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int val = operation(a, b, it);
                st.push(val);
            }else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
