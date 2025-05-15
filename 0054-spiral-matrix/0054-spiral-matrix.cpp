class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (result.size() < m * n) {
            // Traverse right
            for (int j = left; j <= right && result.size() < m * n; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom && result.size() < m * n; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse left
            for (int j = right; j >= left && result.size() < m * n; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
            
            // Traverse up
            for (int i = bottom; i >= top && result.size() < m * n; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return result;
    }
};