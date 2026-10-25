class Solution {
public:
    int bs(int comp, int i , int j , vector<int> &numbers){
        while(i <=  j){
            int k = i + (j - i) / 2;
            if (numbers[k] == comp) return k;
            if (numbers[k] > comp) { 
                j = k -1;
            }else if (numbers[k] < comp){
                i = k+1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        for(int i = 0; i< numbers.size()-1; i++){
            int comp = target - numbers[i];
            res[0] = i + 1;
            // idx -> bs(comp, i + 1, numbers.size() - 1, numbers);
            int idx = bs(comp, i + 1, numbers.size()-1, numbers); 
            if (idx == -1) continue;
            res[1] = idx + 1; // idx + 1 cause 1 based indxing  
            return res;
        }
        return res;
    }
};