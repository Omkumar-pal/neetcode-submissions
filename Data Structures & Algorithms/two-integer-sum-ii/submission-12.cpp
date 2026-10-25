class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        int i = 0;
        int j = numbers.size()-1;
        while(i < j){
            if (numbers[i] + numbers[j] == target){
                res[0] = i + 1;
                res[1] = j + 1;
                return res;
            }else if (numbers[i] + numbers[j] > target){
                j--;
            }else if (numbers[i] + numbers[j] < target){
                i++;
            }
        }
        return {};
    }
};