class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);
        vector<int> pse(n);

        //pse
        for(int i = 0; i< n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if (st.empty()){
                pse[i] = -1;
            }
            if (!st.empty() && heights[st.top()] < heights[i]){
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        //nse
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()){
                nse[i] = n;
            }
            if (!st.empty() && heights[st.top()] < heights[i]){
                nse[i] = st.top();
            }
            st.push(i);
        }
        int area = INT_MIN;
        for(int i = 0; i< n; i++){
            area = max(area, heights[i] * (nse[i] - pse[i] - 1));
        }
        return area;
    }

};
