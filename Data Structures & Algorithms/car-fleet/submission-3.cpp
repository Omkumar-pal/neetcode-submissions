class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> time(target,-1);
        stack<double> st;
        for(int i = 0; i< position.size(); i++){
            time[position[i]] = (double) (target-position[i])/speed[i];
        }

        
        for(int i = target-1;i >=0; i--){
            if (time[i] == -1){
                continue;
            }else if (!st.empty() && st.top() >= time[i]){
                continue;
            }else{
                st.push(time[i]);
            }
        }
        return st.size();
        
    }
};
