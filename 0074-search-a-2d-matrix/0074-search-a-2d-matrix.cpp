class Solution {
public:
    bool helper_fun(int i, int m, vector<vector<int>> &matrix, int target){ 
        for(int j=0;j<m;j++){ 
            if(matrix[i][j] == target) 
            return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();  // no. of column
        int m = matrix[0].size(); // no. of row
        for(int i=0;i<n;i++){ 
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){ 
                return helper_fun(i,m,matrix,target);
            }
        }
        return false;     
}
};