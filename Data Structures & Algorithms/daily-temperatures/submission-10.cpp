class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        pair<int, int> mx;
        int n = temperatures.size()-1;
        vector<int> res(n+1, 0);
        for(int i = n; i >= 0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if (!st.empty() && st.top().first > temperatures[i]){
                res[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};
