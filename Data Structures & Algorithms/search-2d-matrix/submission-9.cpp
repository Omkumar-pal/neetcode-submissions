class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0;
        int r = row-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if (matrix[m][col-1] == target){
                return true;
            }else if (matrix[m][col-1] < target){
                l = m + 1;
            }else {
                r = m -1;
            }
        }

        if( l >= row) return false;
        // l -> my search space
        int x = 0;
        int y = col-1;
        while(x <= y){
            int m = x + (y-x)/2;
            if (matrix[l][m] == target){
                return true;
            }else if (matrix[l][m] < target){
                x = m + 1;
            }else {
                y = m-1;
            }
        }

        return false;

        
    }
};
